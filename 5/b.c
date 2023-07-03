// To write a C program to illustrate the simulation of grep command.

// Present

#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
int main(){
    char fn[10],pat[10],temp[200];
    FILE *fp;
    printf("Enter file name: ");
    scanf("%s",fn);
    printf("Enter pattern to be searched: ");
    scanf("%s",pat);
    fp=fopen(fn,"r");
    if(fp==NULL){
        perror("Cannot open file");
        exit(-1);
    }
    while(!feof(fp)){
        fgets(temp,200,fp);
        if(strstr(temp,pat)){
            printf("%s",temp);
        } 
    }
    fclose(fp);
}
