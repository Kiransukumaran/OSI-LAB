#include<stdio.h>
main()
{
int p,q,r;
r=getpid();
printf("Parent Process id %d",r);
p=fork();
if(p>0)
{
printf("\n**\nParent process\n");
}
else if(p==0)
{
printf("\nChild process\n");
q=getpid();
printf("child process id %d\n",q);
}
else if(p==-1)
{
printf("Error\n");
}
return(0);
}
