#include<stdio.h>
#include<stdlib.h>
#include "sum.h"
int add(CLIENT *clnt,int x,int y)
{
 operands ops;
 int *result;
 ops.x=x;
 ops.y=y;
 result=add_1(&ops,clnt);
 return(*result);
}
int main(int argc,char *argv[])
{
 CLIENT *clnt;
 int x,y;
 clnt=clnt_create(argv[1],sum,sum_ver,"UDP");
 x=atoi(argv[2]);
 y=atoi(argv[3]);
 printf("\n\n%d+%d=%d\n\n",x,y,add(clnt,x,y));
}
 

