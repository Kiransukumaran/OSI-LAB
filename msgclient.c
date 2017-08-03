#include<sys/stat.h>
#include<sys/msg.h>
struct{
 long int mtext;
 char mtype[100];
}buff;
main(){
 int id;
 id=msgget(4589,IPC_CREAT|0666);
 buff.mtext=1;
 gets(buff.mtype);
 msgsnd(id,&buff,sizeof(buff),0);
}
