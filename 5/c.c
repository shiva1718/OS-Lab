// To write a C program to illustrate the execl command using system Calls

#include<stdio.h> 
#include<unistd.h>

// present

int main() {
    int pid;
    pid = fork(); 
    if(pid  == 0){
        printf("Child process\n");
        execl("/bin/ls", "ls", "-l", (char*)0); 

    }
    else if (pid<0){
        printf("cannot create process");
    }
    else{
        printf("Parent process\n"); 
    }
}