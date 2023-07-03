// To write a C program to illustrate the open, read and write for file copy using system Calls.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    char buf[1000],fn1[10],fn2[10];
    int fd1,fd2,n; 
    printf("Enter source file name ");
    scanf("%s",fn1); 
    printf("Enter destination file name ");
    scanf("%s",fn2);
    fd1=open(fn1,O_RDONLY);
    n=read(fd1,buf,1000);
    fd2=open(fn2,O_CREAT|0666);
    n=write(fd2,buf,n);
    close(fd1);
    close(fd2);
    return 0;
}
