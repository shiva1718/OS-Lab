// Page Replacement Algorithm: LFU

// Not perfect!

#include <stdio.h>
#include <stdlib.h>

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
    int freq[10000] = {0};
    int index[k];
    for (int i = 0; i < k; i++) {
        index[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < k; j++) {
            if (arr[j][i] == page[i]) {
                hit++;
                flag = 1;
                freq[page[i]]++;
                index[j] = i;
                printf("hit ");
                break;
            }
        }
        if (!flag) {
            if (i < k) {
                applyFully(arr, i, i, page[i]);
                freq[page[i]]++;
                index[i] = i;
                miss++;
                printf("miss ");
            } else {
                int mn = 0;
                for (int j = 1; j < k; j++) {
                    if (freq[arr[j][i]] < freq[arr[mn][i]]) {
                        mn = j;
                    } else if (freq[arr[j][i]] == freq[arr[mn][i]] && index[j] < index[mn]) {
                        mn = j;
                    }
                }
                applyFully(arr, mn, i, page[i]);
                freq[page[i]]++;
                index[mn] = i;
                miss++;
                printf("miss ");
            }
        }
        for (int j = 0; j < k; j++) {
            printf("%d ", freq[arr[j][i]]);
        }
        printf("\n");
    }
    printf("\n");
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

