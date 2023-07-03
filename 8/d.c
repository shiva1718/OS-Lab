#include<stdio.h>
#include<unistd.h>
void main() {
    int b[20],n,i,pa,p,a,d;
    printf("\nProgram for paging");
    printf("\n enter the no.of pages");
    scanf("%d",&n);
    printf("\nEnter the base address:");
    for(i=1;i<=n;i++) {
        scanf("%d",&b[i]);
    }
    printf("\nEnter the logical address:");
    scanf("%d",&d);
    printf("\n enter the page no");
    scanf("%d",&p);
    if (p < n) {
        pa = b[p]+d;
        a = b[p];
        printf("\n\tPageNo.\t BaseAdd. PhysicalAdd. \n\t %d \t %d \t %d \t ",p,a,pa);
    } else {
        printf("\nInvalid page");
    }
}
