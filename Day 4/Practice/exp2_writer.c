#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 66);
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *str = (char *)shmat(shmid, NULL, 0);

    printf("Enter a string: ");
    getchar();
    fgets(str, 1024, stdin);

    printf("String written to shared memory\n");

    shmdt(str);
    return 0;
}

