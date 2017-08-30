#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define cls() printf("\033[H\033[J")
#define EATINGTIME 1
void *philosopher1();
void *philosopher2();
void *philosopher3();
void *philosopher4();
void *philosopher5();
sem_t sem15,sem12,sem23,sem34,sem45;
int end=0;
main()
{ char a[2];
  pthread_t t1,t2,t3,t4,t5;
  pthread_attr_t at1;
  pthread_attr_init(&at1);
  pthread_attr_setdetachstate(&at1,PTHREAD_CREATE_DETACHED);
  sem_init(&sem15,0,1);
  sem_init(&sem12,0,1);
  sem_init(&sem23,0,1);
   sem_init(&sem34,0,1);
  sem_init(&sem45,0,1);
  cls();
  printf("\n\n\n");
  printf("........");
  printf("\n\n\nDINING PHILOSOPHER PROBLEM");
  printf("\n\t\t\t");
  printf("\n\n\n\t No. OF PHILOSOPHER:5");
  printf("\n\n\t\tNo. OF FORK:5\n\n");
  printf("\n.........\n");
  printf("\n\n\nPRESS ENTER TO CONTINUE....");
  fgets(a,sizeof(a),stdin);
  cls();
  pthread_create(&t1,&at1,philosopher1,NULL);
  pthread_create(&t2,&at1,philosopher2,NULL);
  pthread_create(&t3,&at1,philosopher3,NULL);
  pthread_create(&t4,&at1,philosopher4,NULL);
  pthread_create(&t5,&at1,philosopher5,NULL);
  while(end!=5)
  {
  }
}
void *philosopher1()
{ 
   int i=0;
   printf("\n\t\t PHILOSOPHER_1 THINKING");
  while(i<EATINGTIME)
  { 
    sleep(1);
    sem_wait(&sem15);
    sem_wait(&sem12);
    printf("\n\n\t *PHILOSOPHER_1 EATING\n");
    sleep(1);
    sem_post(&sem15);
    sem_post(&sem12);
    printf("\n\t\tPHILOSOPHER_1 THINKING\n");
    i++;
  }
  end++;
}
void *philosopher2()
{ 
   int i=0;
   printf("\n\t\t PHILOSOPHER_2 THINKING");
  while(i<EATINGTIME)
  { 
    sleep(1);
    sem_wait(&sem12);
    sem_wait(&sem23);
    printf("\n\n\t *PHILOSOPHER_2 EATING\n");
    sleep(1);
    sem_post(&sem12);
    sem_post(&sem23);
    printf("\n\t\tPHILOSOPHER_2 THINKING\n");
    i++;
  }
  end++;
}
void *philosopher3()
{ 
   int i=0;
   printf("\n\t\t PHILOSOPHER_3 THINKING");
  while(i<EATINGTIME)
  { 
    sleep(1);
    sem_wait(&sem23);
    sem_wait(&sem34);
    printf("\n\n\t *PHILOSOPHER_3 EATING\n");
    sleep(1);
    sem_post(&sem23);
    sem_post(&sem34);
    printf("\n\t\tPHILOSOPHER_3 THINKING\n");
    i++;
  }
  end++;
}
void *philosopher4()
{ 
   int i=0;
   printf("\n\t\t PHILOSOPHER_4 THINKING");
  while(i<EATINGTIME)
  { 
    sleep(1);
    sem_wait(&sem34);
    sem_wait(&sem45);
    printf("\n\n\t *PHILOSOPHER_4 EATING\n");
    sleep(1);
    sem_post(&sem34);
    sem_post(&sem45);
    printf("\n\t\tPHILOSOPHER_4 THINKING\n");
    i++;
  }
  end++;
}
void *philosopher5()
{ 
   int i=0;
   printf("\n\t\t PHILOSOPHER_5 THINKING");
  while(i<EATINGTIME)
  { 
    sleep(1);
    sem_wait(&sem45);
    sem_wait(&sem15);
    printf("\n\n\t *PHILOSOPHER_5 EATING\n");
    sleep(1);
    sem_post(&sem45);
    sem_post(&sem15);
    printf("\n\t\tPHILOSOPHER_5 THINKING\n");
    i++;
  }
  end++;
}

