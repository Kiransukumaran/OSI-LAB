#include<stdio.h>
#include<rpc/rpc.h>
#include "sum.h"
int *add_1_svc(operands *argp,struct svc_req *reqstp)
{
 static int result;
 printf("got request:adding %d,%d\n",argp->x,argp->y);
 result=argp->x+argp->y;
 return(&result);
}


