#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], wt[20], tat[20], done[20] = {0};
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("\nGantt Chart:\n|");
    int start_times[20], end_times[20], seq[20], k = 0;

    while (completed < n) {
        int idx = -1, minbt = 99999;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && bt[i] < minbt) {
                minbt = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        start_times[k] = time;
        time += bt[idx];
        end_times[k] = time;
        seq[k++] = idx + 1;

        tat[idx] = time - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        avgwt += wt[idx];
        avgtat += tat[idx];
        done[idx] = 1;
        completed++;
    }

    for (i = 0; i < k; i++)
        printf(" P%d |", seq[i]);
    printf("\n");

    printf("%d", start_times[0]);
    for (i = 0; i < k; i++)
        printf("   %d", end_times[i]);
    printf("\n");

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avgwt / n);
    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nThroughput = %.2f\n", (float)n / time);

    return 0;
}

