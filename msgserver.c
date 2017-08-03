#include<sys/stat.h>
#include<sys/msg.h>
#include<stdio.h>
struct
{
 long int mtype;
 char mtext[100];
}buff;
main()
{
 int id;
 id=msgget(4589,IPC_CREAT|0666);
 msgrcv(id,&buff,sizeof(buff),1,0);
 printf("%s",buff.mtext);
}
