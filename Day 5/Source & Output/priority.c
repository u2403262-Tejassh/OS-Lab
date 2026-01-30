#include <stdio.h>

int main() {
    int n, time = 0, completed = 0;
    int at[20], bt[20], pr[20], wt[20], tat[20], done[20]={0};
    int seq[20], st[20], et[20], k = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT, Priority of P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    while (completed < n) {
        int idx = -1, best = 99999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && pr[i] < best) {
                best = pr[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        st[k] = time;
        seq[k] = idx + 1;
        time += bt[idx];
        et[k++] = time;

        tat[idx] = time - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        avgwt += wt[idx];
        avgtat += tat[idx];
        done[idx] = 1;
        completed++;
    }

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < k; i++)
        printf(" P%d |", seq[i]);
    printf("\n");

    printf("%d", st[0]);
    for (int i = 0; i < k; i++)
        printf("   %d", et[i]);
    printf("\n");

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avgwt / n);
    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nThroughput = %.2f\n", (float)n / time);

    return 0;
}

