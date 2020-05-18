#include<stdio.h>
#include<ctype.h>

struct keytab
{
	char *keyWord;
	int keyCount;
};

char getSymbol(char *text, int pos)
{

	return *(text + pos);
};

int main()
{
	struct keytab keyArray[] = {"auto", 0, "continue", 0, "do", 0, "for", 0, "while", 0, "break", 0, "if", 0, "else", 0, "return", 0};
	char *text, *word;
	int pos = 0, count = 0;

	printf("Type code:\n");
	scanf("%s", text);
	printf("scanf'ed\n");
	while(*word = getSymbol(text, pos) != '\0')
	{
		pos++;
		word++;
		int i;
		for(i = 0; i < sizeof(keyArray) / sizeof(struct keytab); i++)
			if(word == keyArray[i].keyWord)
				keyArray[i].keyCount++;
		printf("\nisspace's condition works\n");
	}
	
	int i;
	for(i = 0; i < sizeof(keyArray) / sizeof(struct keytab); i++)
		printf("%s, %d", keyArray[i].keyWord, keyArray[i].keyCount);

	return 0;
}
