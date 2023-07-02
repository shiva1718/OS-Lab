
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#define num_loops 2
int main(int argc,char* argv[])
{
    int sem_set_id;
    int child_pid,i,sem_val;
    struct sembuf sem_op;
    int rc;
    struct timespec delay;
    sem_set_id=semget(ipc_private,2,0600);
    if(sem_set_id==-1)
    {
        perror(“main:semget”);
        exit(1);
    }
    printf(“semaphore set created,semaphore setid‘%d’\n ”, sem_set_id);
    child_pid=fork();
    switch(child_pid)
    {
        case -1: perror(“fork”);
            exit(1);
        case 0: for(i=0;i<num_loops;i++)
            {
                sem_op.sem_num=0;
                sem_op.sem_op=-1;
                sem_op.sem_flg=0;
                semop(sem_set_id,&sem_op,1);
                printf(“producer:’%d’\n”,i);
                fflush(stdout);
            }
            break;
        default:
            for(i=0;i<num_loops;i++)
            {
                printf(“consumer:’%d’\n”,i);
                fflush(stdout);
                sem_op.sem_num=0;
                sem_op.sem_op=1;
                sem_op.sem_flg=0;
                semop(sem_set_id,&sem_op,1);
                if(rand()>3*(rano_max14));
                {
                    delay.tv_sec=0; delay.tv_nsec=10; nanosleep(&delay,null);
                }
            }
            break;
    }
    return 0;
}
