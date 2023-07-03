// Page replacement Algorithm: FIFO 

#include <stdio.h>

int n;

void applyFully(int (*arr)[n], int cur,int i, int val) {
    for (int iter = i; iter < n; iter++) {
        arr[cur][iter] = val;
    }
}

int main() {
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int k;
    printf("Enter the number of frames: ");
    scanf("%d", &k);
    int arr[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;
        }
    }
    int page[n];
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }
    int cur = 0;
    int miss = 0, hit = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (arr[j][i] == page[i]) {
                flag = 1;
                hit++;
                break;
            }
        }
        if (flag == 0) {
            applyFully(arr, cur,i, page[i]);
            miss++;
            cur = (cur + 1) % k;
        }
    }
    for(int m = 0;m<k;m++){
        for(int j = 0;j<n;j++){
            printf("%d  ", arr[m][j]);
        }
        printf("\n");
    }

    printf("Page hits: %d\n", hit);
    printf("Page faults: %d\n", miss);
    return 0;
}