// To write a C program to illustrate the getpid command using system Calls

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {
    int pid;
    pid = fork(); 
    if(pid  == 0){
        printf("Child process\n");
        printf("Child process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());
    }
    else if (pid<0){
        printf("cannot create process");
    }
    else{
        printf("Parent process\n"); 
        printf("Parent process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());
    }
}