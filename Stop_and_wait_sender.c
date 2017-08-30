#include"stdio.h"
#include"sys/types.h"
#include"netinet/in.h"
#include"string.h"
#include"sys/socket.h"
#include"stdlib.h"
#include"unistd.h"
main()
{
int sd,i,r,bi,nsd,port,frame,prev_frame=0,count=0;
char ack[5],buff[30];
struct sockaddr_in ser,cli;
if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
{
printf("\nsocket problem");
return 0;
}
printf("\n socket created\n");
bzero((char *)&cli,sizeof(ser));
printf("ENTER PORT NUMBER\n");
scanf("%d",&port);
printf("\n port address is %d\n:",port);
ser.sin_family=AF_INET;
ser.sin_port=htons(port);
ser.sin_addr.s_addr=htonl(INADDR_ANY);
bi=bind(sd,(struct sockaddr*)&ser,sizeof(ser));
if(bi==-1)
{
printf("\n bind error,port busy, plz change port in client and server");
return 0;
}
i=sizeof(cli);
listen(sd,5);
nsd=accept(sd,((struct sockaddr*)&cli),&i);
if(nsd==-1)
{
printf("\ncheck the description parameter\n");
return 0;
}
printf("\n connection accepted\n");
while(count<5)
{
ph:
printf("\n sending FRAME %d to the receiver.......\n",prev_frame);
snprintf(buff,sizeof(buff),"%d",prev_frame);
send(nsd,buff,30,0);
r=recv(nsd,ack,5,0);
if(strcmp(ack,"ack")==0||strcmp(ack,"ACK")==0)
{
count++;
if(prev_frame==0)
prev_frame=1;
else
prev_frame=0;
}
else if(strcmp(ack,"nak")==0||strcmp(ack,"NAK")==0)
{
printf("\n NAK :so again send the previous frame....\n");
goto ph;
}
}
printf("\n bye");
send(nsd,"EOF",4,0);
close(sd);
close(nsd);
return 0;
}
