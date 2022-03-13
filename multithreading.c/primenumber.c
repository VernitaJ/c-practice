#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int primenumber(int);

void *workerThread(void *);

void *workerThread(void *num)
{
    int number = atoi(num);
    int true = primenumber(number);
    if (true)
    {
        return (void *)1;
        pthread_exit(NULL);
    }
    return (void *)0;
    pthread_exit(NULL);
}

int primenumber(int number)
{
    if (number == 1 || number == 2)
    {
        return 1;
    }
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    pthread_t t_id[argc - 1];

    char str_arr[100][20];

    // static char primes[argc-1];
    printf("Before using threading\n");
    for (int i = 1; i < argc; i++)
    {
        char *num;
        void *prime;
        int number = atoi(argv[i]);
        pthread_create(&t_id[i], NULL, workerThread, (void *)argv[i]);
        pthread_join(t_id[i], &prime);
        asprintf(&num, "%d", number);
        if (prime)
        {
            strcat(strcpy(str_arr[i], num), " - prime");
        }
        else
            strcat(strcpy(str_arr[i], num), " - not a prime");
    }
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", str_arr[i]);
    }
    printf("After using threading\n");
    
    // pthread_exit(NULL);
    return 0;
}
