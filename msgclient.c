#include<sys/stat.h>
#include<sys/msg.h>
struct
{
 long int mtype;
 char mtext[100];
}buf;
main()
{
 int id;
 id=msgget(4589,IPC_CREAT|0666);
 buf.mtype=1;
 gets(buf.mtxt);
 msgsnd(id,&buf,sizeof(buf),0);
}
