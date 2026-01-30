#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 67);
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    int *num = (int *)shmat(shmid, NULL, 0);

    printf("Enter number: ");
    scanf("%d", num);

    shmdt(num);
    return 0;
}

