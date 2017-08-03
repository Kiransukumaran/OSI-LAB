#include<stdio.h>
main()
{
int p[2],pid,ppid,f;
char a[100];
pipe(p);
f=fork();
pid=getpid();
ppid=getppid();
if(f==0)
{
printf("Child process id %d\n",pid);
printf("Parent process id %d\n",ppid);
printf("Enter the child msg..\n");
fgets(a,sizeof(a),stdin);
write(p[1],a,sizeof(a));
sleep(1);
read(p[0],a,sizeof(a));
printf("\nChild read and print parent msg :");
puts(a);
}
else
{
read(p[0],a,sizeof(a));
printf("\nParent read and print child msg :");
puts(a);
printf("\nEnter the parent msg..\n");
fgets(a,sizeof(a),stdin);
write(p[1],a,sizeof(a));
}
}
