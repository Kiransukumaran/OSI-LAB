#include"stdio.h"
#include"sys/types.h"
#include"netinet/in.h"
#include"string.h"
#include"sys/socket.h"
#include"stdlib.h"
#include"unistd.h"
int main()
{
int sd,con,port,i;
char content[30],ack[3];
struct sockaddr_in cli;
if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
{
printf("\nsocket problem");
return 0;
}
bzero((char *)&cli,sizeof(cli));
cli.sin_family=AF_INET;
printf("ENTER PORT NUMBER:\n");
scanf("%d",&port);
cli.sin_port=htons(port);
cli.sin_addr.s_addr=htonl(INADDR_ANY);
con=connect(sd,(struct sockaddr*)&cli,sizeof(cli));
if(con==-1)
{
printf("\n connection error");
return 0;
}
i=recv(sd,content,30,0);
while(strcmp(content,"EOF")!=0)
{
printf("received from sender:frame %s \n",content);
ph:
printf("\n acknowledgement(ACK/NAK):");
scanf("%s",ack);
if(!(strcmp(ack,"ack")==0||strcmp(ack,"nak")==0||strcmp(ack,"ACK")||strcmp(ack,"NAK")==0))
{
printf("\n not a valid acknowledgement.....use ACK or NAK....\n");
goto ph;
}
send(sd,ack,5,0);
i=recv(sd,content,30,0);
}
printf("\n bye");
close(sd);
return 0;
}
