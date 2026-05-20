#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

void loop()
{
    int count =0;
    while(count<5)
    {
        printf("T1:%d\n",count);
        count++;
       // sleep(1);
    }
}
void loop_2()
{
    int count =5;
    while(count<10)
    {
        printf("T2:%d\n",count);
        count++;
        //sleep(1);
    }
}
void main()
{
    pthread_t tid;
    pthread_t tid2;
    /*In Normal priority Both can equally split*/
    // pthread_create(&tid,NULL,(void*)loop,NULL);
    // pthread_create(&tid2,NULL,(void*)loop_2,NULL);
    
    // //Without join it wont work
    // pthread_join(tid,NULL);
    // pthread_join(tid2,NULL);
    
    pthread_create(&tid,NULL,(void*)loop,NULL);
    pthread_create(&tid2,NULL,(void*)loop_2,NULL);
  
    struct sched_param param1;
    struct sched_param param2;

    // Higher priority
    param1.sched_priority = 80;

    // Lower priority
    param2.sched_priority = 0;
    
    pthread_setschedparam(tid, SCHED_FIFO, &param1);
    pthread_setschedparam(tid2, SCHED_FIFO, &param2);
    
    //Without join it wont work
    pthread_join(tid2,NULL);
    pthread_join(tid,NULL);

}
