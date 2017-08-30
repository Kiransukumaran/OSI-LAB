#include<stdio.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
int main()
{
int clntsocket,i,a[10],n;
struct sockaddr_in serveraddr;
socklen_t len;
struct hostent *server;
char msg[50];
bzero(msg,sizeof(msg));
clntsocket =socket(AF_INET,SOCK_STREAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5015);
server=gethostbyname("127.0.0.1");
bcopy((char *)server->h_addr,(char *)&serveraddr.sin_addr.s_addr,sizeof(server->h_addr));
connect(clntsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("\nconnection process\n");
printf("\nenter array size: \n");
scanf("%d",&n);
printf("\nsending array size  to server\n");
write(clntsocket,&n,sizeof(n));
printf("\nenter 5 numbers: \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\nsending array  to server\n");
write(clntsocket,&a,sizeof(a));
printf("\nreceiving acknowledgement from server\n");
read(clntsocket,msg,sizeof(msg));
printf("\nacknowledgement is %s\n",msg);
close(clntsocket);
return(0);
}
