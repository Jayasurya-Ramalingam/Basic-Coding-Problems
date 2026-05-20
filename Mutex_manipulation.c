#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//semaphore declaration
pthread_mutex_t mlock;
int cnt=0;

void worker_Consumer_problem(int Value)
{
    printf("Thread %lu is waiting\n", pthread_self());
    pthread_mutex_lock(&mlock);
    printf("Thread %lu is Entered Critical\n", pthread_self());
    cnt++;
    sleep(1);
    printf("Thread Executed Successfully:%d\n",cnt);
    pthread_mutex_unlock(&mlock);
    printf("Thread %lu is Left\n", pthread_self());
}

void main()
{
    pthread_t tid;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    
    pthread_mutex_init(&mlock,NULL);
    
    pthread_create(&tid,NULL,(void*)worker_Consumer_problem,12);
    pthread_create(&tid2,NULL,(void*)worker_Consumer_problem,15);
    pthread_create(&tid3,NULL,(void*)worker_Consumer_problem,12);
    pthread_create(&tid4,NULL,(void*)worker_Consumer_problem,15);
  

    //Without join it wont work
    pthread_join(tid2,NULL);
    pthread_join(tid,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
}
