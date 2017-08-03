#include<sys/stat.h>
#include<sys/msg.h>
#include<stdio.h>
struct
{
 long int mtype;
 char mtext[100];
}buf;
main()
{
 int id;
 id=msgget(4589,IPC_CREAT|0666);
 msgrcv(id,&buf,sizeof(buf),1,0);
 printf("%s",buf.mtxt);
}
