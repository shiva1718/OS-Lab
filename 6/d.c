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
    // Note: process with the highest priority numbers are executed first
    int time = 0;
    int done = 0;
    while (done < n) {
        int max = INT_MIN;
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && burstTime[i] != 0 && priority[i] > max) {
                max = priority[i];
                cur = i;
            }
        }
        if (cur == -1) {
            time++;
            continue;
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
    double avgWaitingTime = 0;
    double avgTurnaroundTime = 0;
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTimeCopy[i], waitingTime[i], turnaroundTime[i], completionTime[i]);
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    printf("Average waiting time: %lf\n", avgWaitingTime / n);
    printf("Average turnaround time: %lf\n", avgTurnaroundTime / n);
    return 0;
}