#include<stdio.h>
void main()
{
 int a[100],buff[100];
 int pid,p1[2],p2[2],i,j,n,temp;
 pipe(p1);
 pipe(p2);
 pid=fork();
 if(pid>0)
 {
  printf("Parent process\n");
  close(p1[0]);
  close(p2[1]);
  printf("Enter the limit\n");
  scanf("%d",&n);
  write(p1[1],&n,sizeof(n));
  printf("Enter the array: ");
  for(i=0;i<n;i++)
   scanf("%d",&buff[i]);
   write(p1[1],buff,sizeof(buff));
  sleep(1);
  read(p2[0],buff,sizeof(buff));
  printf("Sorted array\n");
  for(i=0;i<n;i++)
   printf("\n%d",buff[i]);
 }
 else
 {
  read(p1[0],&n,sizeof(n));
  read(p1[0],&a,sizeof(a));
  for(i=0;i<n-1;i++)
   for(j=0;j<n-i-1;j++)
    if(a[j]>a[j+1])
    {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
    }
 write(p2[1],a,sizeof(a));
 }printf("\n");
}
