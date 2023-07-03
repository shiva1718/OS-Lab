// To write a C program to illustrate the lstat command using system Calls

// #include<stdio.h>
// #include<unistd.h>
// #include<stdlib.h>
// #include<sys/stat.h>
// #include<sys/types.h>

// void main() {
//     int pid;
//     pid = fork(); 
//     if(pid  == 0){
//         printf("Child process\n");
//         struct stat buf;
//         lstat("g.c", &buf);
//         printf("File size: %d\n", buf.st_size);
//         printf("File inode: %d\n", buf.st_ino);
//         printf("File uid: %d\n", buf.st_uid);
//         printf("File gid: %d\n", buf.st_gid);
//         printf("File mode: %d\n", buf.st_mode);
//     }
//     else if (pid<0){
//         printf("cannot create process");
//     }
//     else{
//         printf("Parent process\n"); 
//         struct stat buf;
//         lstat("g.c", &buf);
//         printf("File size: %d\n", buf.st_size);
//         printf("File inode: %d\n", buf.st_ino);
//         printf("File uid: %d\n", buf.st_uid);
//         printf("File gid: %d\n", buf.st_gid);
//         printf("File mode: %d\n", buf.st_mode);
//     }
// }

#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char **argv)
{
struct stat statbuf;
if(lstat(argv[1],&statbuf)==-1) 
printf("Error : cannot find file information ");
else
{
 printf("\n File %s ", argv[1]); 
printf("\n Inode number %lu",statbuf.st_ino); 
printf("\n UID %d",statbuf.st_uid);
printf("\n GID %d",statbuf.st_gid); 
printf("\n File size in bytes %lu",statbuf.st_size);
}
return 0;
}
