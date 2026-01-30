#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct fact {
    int nfact;
    int rfact;
    int nrfact;
};

int factorial(int x) {
    int f = 1;
    for (int i = 1; i <= x; i++)
        f *= i;
    return f;
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(struct fact), IPC_CREAT | 0666);

    struct fact *data = (struct fact *)shmat(shmid, NULL, 0);

    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);

    data->nfact = factorial(n);
    data->rfact = factorial(r);
    data->nrfact = factorial(n - r);

    printf("Factorials written to shared memory\n");

    shmdt(data);
    return 0;
}

