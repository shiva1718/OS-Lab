// To write a C program to illustrate the lstat command using system Calls

// present

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
