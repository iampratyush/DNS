#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<arpa/inet.h>
int main(int argc, char *argv[])
{
	int i=0;
	struct hostent * host;
	host = gethostbyname(argv[1]);
	printf("%s\n",host->h_name);
	char ** aliase;
	aliase=NULL;	
	aliase=host-> h_aliases;
	while(aliase[i])
	{
		printf("%s\n",aliase[i]);
		i++;
	}
	char ** addr=host->h_addr_list;
	printf("%d\n",host->h_length);
	while(addr[i])
	{
		printf("%s\n",inet_ntoa(*(struct in_addr *) addr[i]));
		i++;
	}	
	exit(0);
	}
	
