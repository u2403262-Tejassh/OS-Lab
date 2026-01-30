#include <stdio.h>

int main() {
    int n;
   
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[20], wt[20], tat[20];   // Arrays
    int i;

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // First process waiting time is 0
    wt[0] = 0;

    // Calculate waiting times
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate turnaround times
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
