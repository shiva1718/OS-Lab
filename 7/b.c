// Inter process communication using shared memory

// #include <stdio.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <sys/types.h>
// #include <unistd.h>

// int main() {
//   int shmid;
//   key_t key;
//   char *shm, *s;

//   key = 5678;

//   if ((shmid = shmget(key, 27, IPC_CREAT | 0666)) < 0) {
//     perror("shmget");
//     return 1;
//   }

//   if ((shm = (char *)shmat(shmid, NULL, 0)) == (char *)-1) {
//     perror("shmat");
//     return 1;
//   }

//   s = shm;

//   for (char c = 'a'; c <= 'z'; c++) {
//     *s++ = c;
//   }

//   *s = '\0';

//   while (*shm != '*') {
//     sleep(1);
//   }

//   return 0;
// }

// #include<stdio.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include<stdlib.h>
// #include<sys/wait.h>
// #include<unistd.h>

// int main()
// {
// if(fork()==0)
// {
// key_t key = ftok("shmfile",65);
// int shmid = shmget(key,1024,0666|IPC_CREAT);
// char *str = (char *) shmat(shmid,(void*)0,0);
// printf("Write Data : \n");
// scanf("%s",str);
// printf("Child process written in memory: %s\n",str);
// shmdt(str);
// }
// else
// {
// wait(0);
// key_t key = ftok("shmfile",65);
// int shmid = shmget(key,1024,0666|IPC_CREAT);
// char *str = (char *) shmat(shmid,(void*)0,0);
// printf("Parent reads from memory       : %s\n",str);
// shmdt(str);
// shmctl(shmid,IPC_RMID,NULL);
// }
// return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h> 
#define shm_size 1024
int main(int argc,char * argv[])
{
key_t key; 
int shmid; 
char *data; 
int mode; 
if(argc>2)
{
fprintf(stderr,"usage:stdemo[data_to_writte]\n"); 
exit(1);
}
if((shmid=shmget(key,shm_size,0644/IPC_CREAT))==-1)
{
perror("shmget");
exit(1);
}
data=(char *) shmat(shmid,(void *)0,0); 
if(data==(char *)(-1))
{
perror("shmat");
exit(1);
}
if(argc==2)
printf("writing to segment:%s\n",data); 
if(shmdt(data)==-1)
{
perror("shmdt");
exit(1);
}
return 0;
}


// INCOMPLETE