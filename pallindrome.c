#include<stdio.h>
#include<string.h>
void main()
{
 int temp,num1,pid,p1[2],p2[2],num2,r,x=0;
 char a[100];
 pipe(p1);
 pipe(p2);
 pid=fork();
 if(pid>0)
 {
  printf("Parent process\n");
  close(p1[0]);
  close(p2[1]);
  printf("Enter the number\n");
  scanf("%d",&num1);
  write(p1[1],&num1,sizeof(num1));
  sleep(1);
  read(p2[0],&a,sizeof(a));
  printf("%s",a);
 }
 else 
 {
  read(p1[0],&num2,sizeof(num2));
  temp=num2;
  while(num2>0)
  {
   r=num2%10;
   x=x*10+r;
   num2=num2/10;
  }

  printf("Reversed number:%d\n",x);
  if(temp==x)
  write(p2[1],"pallindrome\n",12);
  else
  write(p2[1],"not palindrome\n",16);
 
}
}
