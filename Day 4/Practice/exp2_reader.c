#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>

int main() {
    key_t key = ftok("shmfile", 66);
    int shmid = shmget(key, 1024, 0666);

    char *str = (char *)shmat(shmid, NULL, 0);

    int vowels = 0, digits = 0, symbols = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            vowels++;
        else if (isdigit(c))
            digits++;
        else if (!isspace(c) && !isalpha(c))
            symbols++;
    }

    printf("Vowels: %d\nDigits: %d\nSymbols: %d\n", vowels, digits, symbols);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

