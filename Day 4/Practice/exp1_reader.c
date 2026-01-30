#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct fact {
    int nfact;
    int rfact;
    int nrfact;
};

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(struct fact), 0666);

    struct fact *data = (struct fact *)shmat(shmid, NULL, 0);

    int nCr = data->nfact / (data->rfact * data->nrfact);
    printf("nCr value = %d\n", nCr);

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

