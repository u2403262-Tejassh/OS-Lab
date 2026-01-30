#include <stdio.h>
#include <limits.h>

void fcfs();
void sjf();
void rr();
void priority_np();

int main() {
    int ch;
    do {
        printf("\n===== CPU SCHEDULING =====");
        printf("\n1. FCFS");
        printf("\n2. SJF (Non-Preemptive)");
        printf("\n3. Round Robin");
        printf("\n4. Priority (Non-Preemptive)");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: fcfs(); break;
            case 2: sjf(); break;
            case 3: rr(); break;
            case 4: priority_np(); break;
        }
    } while (ch != 5);

    return 0;
}
void fcfs() {
    int n, i, j, time = 0;
    int pid[20], at[20], bt[20], ct[20], wt[20], tat[20];
    float avgwt = 0, avgtat = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort by arrival time
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (at[i] > at[j]) {
                int t;
                t=at[i]; at[i]=at[j]; at[j]=t;
                t=bt[i]; bt[i]=bt[j]; bt[j]=t;
                t=pid[i]; pid[i]=pid[j]; pid[j]=t;
            }

    // Compute times
    for (i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    // Gantt chart (PROCESS LINE)
    printf("\nGantt Chart:\n|");
    for (i = 0; i < n; i++)
        printf(" P%d |", pid[i]);

    // Gantt chart (TIME LINE)
    printf("\n%d", at[0]);
    for (i = 0; i < n; i++)
        printf("   %d", ct[i]);
    printf("\n");

    printf("\nP AT BT WT TAT\n");
    for (i = 0; i < n; i++)
        printf("P%d %d %d %d %d\n", pid[i], at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage WT = %.2f", avgwt/n);
    printf("\nAverage TAT = %.2f", avgtat/n);
    printf("\nThroughput = %.2f\n", (float)n/ct[n-1]);
}
void sjf() {
    int n, time = 0, completed = 0;
    int at[20], bt[20], wt[20], tat[20], done[20]={0};
    int seq[20], et[20], k = 0;
    float avgwt=0, avgtat=0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (int i=0;i<n;i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    while (completed < n) {
        int idx=-1, min=INT_MAX;
        for (int i=0;i<n;i++)
            if (at[i]<=time && !done[i] && bt[i]<min) {
                min=bt[i]; idx=i;
            }

        if (idx==-1) { time++; continue; }

        seq[k]=idx+1;
        time+=bt[idx];
        et[k++]=time;

        tat[idx]=time-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        avgwt+=wt[idx];
        avgtat+=tat[idx];
        done[idx]=1;
        completed++;
    }

    printf("\nGantt Chart:\n|");
    for (int i=0;i<k;i++) printf(" P%d |", seq[i]);

    printf("\n0");
    for (int i=0;i<k;i++) printf("   %d", et[i]);
    printf("\n");

    printf("\nAverage WT = %.2f", avgwt/n);
    printf("\nAverage TAT = %.2f", avgtat/n);
    printf("\nThroughput = %.2f\n", (float)n/time);
}
void rr() {
    int n, tq, time=0, completed=0;
    int at[20], bt[20], rt[20], wt[20]={0};
    int seq[100], et[100], k=0;

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(completed<n){
        int progress=0;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                progress=1;
                seq[k]=i+1;

                if(rt[i]>tq){
                    time+=tq;
                    rt[i]-=tq;
                } else {
                    time+=rt[i];
                    wt[i]=time-at[i]-bt[i];
                    rt[i]=0;
                    completed++;
                }
                et[k++]=time;
            }
        }
        if(!progress) time++;
    }

    printf("\nGantt Chart:\n|");
    for(int i=0;i<k;i++) printf(" P%d |",seq[i]);

    printf("\n0");
    for(int i=0;i<k;i++) printf("   %d",et[i]);
    printf("\n");
}
void priority_np() {
    int n,time=0,completed=0;
    int at[20],bt[20],pr[20],done[20]={0};
    int seq[20],et[20],k=0;

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter AT BT Priority of P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
    }

    while(completed<n){
        int idx=-1,best=INT_MAX;
        for(int i=0;i<n;i++)
            if(at[i]<=time && !done[i] && pr[i]<best){
                best=pr[i]; idx=i;
            }

        if(idx==-1){ time++; continue; }

        seq[k]=idx+1;
        time+=bt[idx];
        et[k++]=time;
        done[idx]=1;
        completed++;
    }

    printf("\nGantt Chart:\n|");
    for(int i=0;i<k;i++) printf(" P%d |",seq[i]);

    printf("\n0");
    for(int i=0;i<k;i++) printf("   %d",et[i]);
    printf("\n");
}

