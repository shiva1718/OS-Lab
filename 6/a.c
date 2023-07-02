// Round-Robin scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

// to write a c program to implement round robin scheduling algorithm

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], waitingTime[n], turnaroundTime[n], completionTime[n], burstTimeCopy[n];
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
        burstTimeCopy[i] = burstTime[i];
    }
    int quantum;
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    int time = 0;
    int done = 0;
    int cur = 0;
    while (done < n) {
        int min = quantum < burstTime[cur] ? quantum : burstTime[cur];
        burstTime[cur] -= min;
        time += min;
        // printf("Completing %d for %d\n", cur + 1, min);
        if (min != 0 && burstTime[cur] == 0) {
            done++;
            completionTime[cur] = time;
            waitingTime[cur] = time - burstTimeCopy[cur];
            turnaroundTime[cur] = time;
        }
        cur = (cur + 1) % n;
    }
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTimeCopy[i], waitingTime[i], turnaroundTime[i], completionTime[i]);
    }
    return 0;
}