// To write a C program to illustrate the execv command using system Calls

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {
    int pid;
    pid = fork(); 
    if(pid  == 0){
        printf("Child process\n");
        char *args[]={"ls","-l",NULL}; 
        execv("/bin/ls",args); 
        printf("Ending-----\n");
    }
    else if (pid<0){
        printf("cannot create process");
    }
    else{
        printf("Parent process\n"); 
    }
}