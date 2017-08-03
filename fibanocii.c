#include<stdio.h>
#include<string.h>
main()
{
 int p[2],pid,a,b,c,n;
 if(pipe(p)==-1)
 {
  printf("\nError in pipe connection\n");
  exit(0);
 }
 pid=fork();
 if(pid>0)
 {
  printf("\nParent process");
  printf("\nFibanocci series");
  printf("\nEnter the limit  ");
  scanf("%d",&n);
  close(p[0]);
  write(p[1],&n,sizeof(n));
  close(p[1]);
  exit(0);
 }
 else
 {
  close(p[1]);
  read(p[0],&n,sizeof(n));
  printf("\nChild process");
  a=0;b=1;
  close(p[0]);
  printf("\nFibanocci series is");
  printf("\n%d\n%d\n",a,b);
  while(n>2)
  {
   c=a+b;
   printf("%d\n",c);
   a=b;b=c;n--;
  }
 }
}

