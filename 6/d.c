// Priority Scheduling

#include<stdio.h>
#include<stdlib.h>

// to write a c program to implement priority scheduling algorithm

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], waitingTime[n], turnaroundTime[n], completionTime[n], burstTimeCopy[n], arrivalTime[n], priority[n];
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
        burstTimeCopy[i] = burstTime[i];
    }
    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrivalTime[i]);
    }
    printf("Enter the priorities: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }
    int time = 0;
    int done = 0;
    while (done < n) {
        int max = -1;
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (burstTime[i] != 0 && priority[i] > max) {
                max = priority[i];
                cur = i;
            }
        }
        burstTime[cur] = 0;
        time += burstTimeCopy[cur];
        printf("Completing %d for %d\n", cur + 1, burstTimeCopy[cur]);
        if (burstTimeCopy[cur] != 0) {
            done++;
            completionTime[cur] = time;
            waitingTime[cur] = time - burstTimeCopy[cur] - arrivalTime[cur];
            turnaroundTime[cur] = time - arrivalTime[cur];
        }
    }
    double avgWatingTime = 0;
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTimeCopy[i], waitingTime[i], turnaroundTime[i], completionTime[i]);
        avgWatingTime += waitingTime[i];
    }
    printf("Average waiting time: %lf\n", avgWatingTime / n);
    return 0;
}