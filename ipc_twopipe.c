#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
char buff[100];
int p1[2],p2[2],i;
pipe(p1);
pipe(p2);
if(fork()==0)
{
 close(p1[0]);
 close(p2[1]);
 printf("\nOpening child"); 
if(write(p1[1],"hello",6)<0)
  printf("\nChild: Write error...");
 if(read(p2[0],buff,sizeof(buff))<0)
  printf("\nChild: Read error...");
 else
 {
  printf("\nRecieved msg from parent:Parent says %s\n",buff);
 }
 printf("\nClosing child\n");
}
else
{
 close(p1[1]);
 close(p2[0]);
 printf("\nOpening parent");
if(read(p1[0],buff,sizeof(buff))<0)
 printf("\nParent : read error\n");
else
 printf("\nRecieved msg from child: child says %s",buff);
if(write(p2[1],"hai",4)<0)
{
 printf("\nParent write error");
}
wait(0);
printf("\nclosing parent\n");
}
exit(0);
}
