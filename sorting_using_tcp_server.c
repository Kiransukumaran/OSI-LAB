#include<stdio.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
int main()
{
int clntsocket,serversocket,a[50],i,temp,j,n;
char msg[50];
struct sockaddr_in serveraddr,clntaddr;
socklen_t len;
bzero((char *)msg,sizeof(msg));
serversocket=socket(AF_INET,SOCK_STREAM,0);
printf("\nSERVER PROCESS\n");
bzero((char *)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5015);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char *)&clntaddr,sizeof(clntaddr));
len=sizeof(clntaddr);
printf("\n*****\n");
listen(serversocket,5);
printf("\nwaitng for client connectivity\n");
clntsocket=accept(serversocket,(struct sockaddr*)&clntaddr,&len);
printf("\nclient connectivity is received\n");
printf("\nreading array size from client\n");
read(clntsocket,&n,sizeof(n));
printf("\narray size  is:%d\n",n);
printf("\nreading array from client\n");
read(clntsocket,&a,sizeof(a));
printf("\narray is:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
printf("\nsending acknowledgement to client\n");
write(clntsocket,"your message is received",sizeof("your message is received"));
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
if (a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
printf("\nsorted array is:\n");
for(i=0;i<5;i++)
printf("%d\n",a[i]);
close(clntsocket);
close(serversocket);
}
