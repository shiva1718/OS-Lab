#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
DIR *dp;
struct dirent *dirp;
if (argc != 2) 
{
printf("a single argument (the directory name) is required\n");
return 1;
}
if ( (dp = opendir(argv[1])) == NULL) 
{
printf("can't open %s\n",argv[1]);
return 1;
}
while ( (dirp = readdir(dp)) != NULL)
printf("%s %ld\n",dirp->d_name,dirp->d_ino);
closedir(dp);
return 0;
}
