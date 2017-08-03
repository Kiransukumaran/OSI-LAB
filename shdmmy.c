#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
main()
{
 char *a;
 key_t key=ftok("shdmmy.c",'A');
 int shmid=shmget(key,sizeof(char),IPC_CREAT|0666);
 a=(char*)shmat(shmid,0,0);
 if(shmid!=-1)
  printf("Shared m/y created with id: %d\n",shmid);
 else
  printf("Shared m/y not created\n"); 
}
