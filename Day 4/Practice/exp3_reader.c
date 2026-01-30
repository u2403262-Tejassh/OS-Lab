#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 67);
    int shmid = shmget(key, sizeof(int), 0666);

    int *num = (int *)shmat(shmid, NULL, 0);

    int original = *num;
    int rev = 0, temp = original;

    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    printf("Reverse = %d\n", rev);

    if (original == rev)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome\n");

    shmdt(num);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

