// Memory Allocation - Worst Fit

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int allocated;
    int resource;
} MemBlock;

int main(){
    int n, n2;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);

    int m = 0;
    int unallocatedResource[100] = {0};

    MemBlock blocks[n];

    printf("Enter the sizes of each memory block: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
        blocks[i].resource = -2;
    }
    printf("Enter the number of resources: ");
    scanf("%d", &n2);
    int resourceSize[n2];
    printf("Enter the sizes of each resource:\n");
    for (int i = 0; i < n2; i++) scanf("%d", &resourceSize[i]);

    for(int i = 0;i<n2;i++){
        int assigned = 0;
        int max = -1;
        int maxIndex = -1;
        for (int j = 0; j < n; j++) {
            if (blocks[j].allocated == 0 && resourceSize[i] <= blocks[j].size && blocks[j].size > max) {
                max = blocks[j].size;
                maxIndex = j;
                assigned = 1;
            }
        }
        if (assigned == 1) {
            blocks[maxIndex].resource = i;
            blocks[maxIndex].allocated = 1;
        }
        else unallocatedResource[m++] = i;
    }

    printf("Allocated Resources\n");
    for(int i = 0;i<n;i++){
        printf("Block%d has the resource of %d\n", i + 1, blocks[i].resource + 1);
    }
    printf("Unallocated Resource\n");
    for(int i = 0;i<m;i++){
        printf("%d ", unallocatedResource[i] + 1);
    }
}