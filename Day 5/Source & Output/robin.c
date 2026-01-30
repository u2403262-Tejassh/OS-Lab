#include <stdio.h>

int main() {
    int n, tq, time = 0, completed = 0;
    int at[20], bt[20], rt[20], wt[20]={0}, tat[20];
    int seq[100], tms[100], k = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (completed < n) {
        int progressed = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                progressed = 1;
                seq[k] = i + 1;
                tms[k++] = time;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
        if (!progressed)
            time++;
    }

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < k; i++)
        printf(" P%d |", seq[i]);
    printf("\n");

    printf("%d", tms[0]);
    for (int i = 0; i < k; i++)
        printf("   %d", (i == k-1) ? time : tms[i+1]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avgwt / n);
    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nThroughput = %.2f\n", (float)n / time);

    return 0;
}

