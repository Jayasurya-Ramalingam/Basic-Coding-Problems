#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//semaphore declaration
sem_t sid;
int cnt=0;

void worker_Consumer_problem(int Value)
{
    printf("Thread %lu is waiting\n", pthread_self());
    //sem_wait(&sid);
    cnt++;
    sleep(1);
    printf("Thread Executed Successfully:%d\n",cnt);
    //sem_post(&sid);
    
}

void main()
{
    pthread_t tid;
    pthread_t tid2;

    sem_init(&sid,0,1);
    
    pthread_create(&tid,NULL,(void*)worker_Consumer_problem,12);
    pthread_create(&tid2,NULL,(void*)worker_Consumer_problem,15);
  

    //Without join it wont work
    pthread_join(tid2,NULL);
    pthread_join(tid,NULL);

    sem_destroy(&sid);
}
