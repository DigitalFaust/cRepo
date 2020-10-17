#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include"hacking.h"
#include"hacking-network.h"

#define PORT 80 //Port for user's connection
#define WEBROOT "./webroot"

void handle_connection(int, struct sockaddr_in *); //It opens web requests
int get_file_size(int); //It returns size of file opened with pointed descriptor

int main(void)
{
	int sockfd, new_sockfd, yes = 1; //Listening socket in variable sockfd, new connection in new_sockfd
	struct sockaddr_in host_addr, client_addr; //My address data
	socklen_t sin_size;

	printf("Accepting web requests on port %d\n", PORT);

	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		fatal("in socket");

	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		fatal("due setting parameter SO_REUSEADDR");

	host_addr.sin_family = AF_INET; //Local order of bytes
	host_addr.sin_port = htons(PORT); //Short integer, net order of bytes
	host_addr.sin_addr.s_addr = INADDR_ANY; //It is filled by my IP automatically
	memset(&(host_addr.sin_zero), '\0', 8); //Nulify left structure

	if(bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
		fatal("connection with socket");

	if(listen(sockfd, 20) == -1)
		fatal("listening to from socket's side");
	
	while(1) //Cycle of function accept
	{
		sin_size = sizeof(struct sockaddr_in);
		new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
		if(new_sockfd == -1)
			fatal("acception connection");
		handle_connection(new_sockfd, &client_addr);
	}
	return 0;
}

/* The function processes connections of a transmitted socket with a
 * transmitted client's address. Connection is processed as a web-request,
 * function answers using a connected socket. A transmitted socket closes
 * at the end of the function
*/
void handle_connection(int sockfd, struct sockaddr_in *client_addr_ptr)
{
	unsigned char *ptr, request[500], resourse[500];
	int fd, length;

	length = recv_line(sockfd, request);
	printf("Accepting request from %s:%d \"%s\"\n", inet_ntoa(client_addr_ptr->sin_addr), ntohs(client_addr_ptr->sin_port), request);
	ptr = strstr(request, " HTTP/"); //Searching correct request
	if(ptr == NULL) //In this case a request isn't correct
		printf("NOT HTTP!\n");
	else
	{
		*ptr = 0; //Finishing buffer in the end of URL's address
		ptr = NULL; //Setting ptr on NULL (using as a flag for an incorrect requests)
		
		if(strncmp(request, "GET ", 4) == 0) //GET request
			ptr = request + 4; //ptr is URL
		if(strncmp(request, "HEAD ", 5) == 0) //HEAD request
			ptr = request + 5;
		if(ptr == NULL) //Then request is not recognized
			printf("\tUnknown request!\n");
		else //Correct request with ptr pointing on the name of resourse
		{
			if(ptr[strlen(ptr) - 1] == '/') //For resourses ending on '/' to add in the end 'index.html'
				strcat(ptr, "index.html");
			strcpy(resourse, WEBROOT); //Start resourse from way to root directory
			strcat(resourse, ptr); //Join to way to resourse
			fd = open(resourse, O_RDONLY, 0); //Trying to open the file
			printf("\tOpenning \'%s\'\n", resourse);
			if(fd == -1) //If file is not found
			{
				printf(" 404 Not found\n");
				send_string(sockfd, "HTTP/1.0 404 NOT FOUND\r\n");
				send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
				send_string(sockfd, "<html><head><title>404 not found</title></head>");
				send_string(sockfd, "<body><h1>URL not found</h1></body></html>\r\n");
			}
			else //Otherwise work with the file
			{
				printf(" 200 OK\n");
				send_string(sockfd, "HTTP/1.0 200 OK\r\n");
				send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
				if(ptr == request + 4) //It's a GET request
				{
					if((length = get_file_size(fd)) == -1)
							fatal("in case of accepting size of resourse of the file");
					if((ptr = (unsigned char *) malloc(length)) == NULL)
						fatal("in case of memory allocation for reading the resourse");
					read(fd, ptr, length); //Reading file in memory
					send(sockfd, ptr, length, 0); //Send it on socket
					free(ptr); //Free memory from file
				}
				close(fd);
			}
		}
	}
	shutdown(sockfd, SHUT_RDWR);
}

/*Function accepts descriptor the opened file and returns size
 * of associated with it file. In case of fail it returns -1
 */
int get_file_size(int fd)
{
	struct stat stat_struct;

	if(fstat(fd, &stat_struct) == -1)
		return -1;
	return (int) stat_struct.st_size;
}
