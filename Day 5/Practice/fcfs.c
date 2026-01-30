#include <stdio.h>

int main() {
    int n, i, j, time = 0;
    int pid[20], at[20], bt[20], ct[20], wt[20], tat[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    /* Sort by arrival time */
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (at[i] > at[j]) {
                int t;
                t = at[i]; at[i] = at[j]; at[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }

    /* Gantt chart calculation */
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    /* Gantt Chart */
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++)
        printf(" P%d |", pid[i]);
    printf("\n");

    printf("%d", at[0]);
    for (i = 0; i < n; i++)
        printf("   %d", ct[i]);
    printf("\n");

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avgwt / n);
    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nThroughput = %.2f\n", (float)n / ct[n-1]);

    return 0;
}

