// First come First Serve Scheduling

#include<stdio.h>
#include<stdlib.h>

// to write a c program to implement first come first serve scheduling algorithm

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], waitingTime[n], turnaroundTime[n], completionTime[n], burstTimeCopy[n], arrivalTime[n];
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
        burstTimeCopy[i] = burstTime[i];
    }
    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrivalTime[i]);
    }
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += burstTime[i];
        completionTime[i] = time;
        waitingTime[i] = time - burstTimeCopy[i] - arrivalTime[i];
        turnaroundTime[i] = time - arrivalTime[i];
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