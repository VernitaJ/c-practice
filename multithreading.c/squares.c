#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define RAND_MAX 3;

void *sumsquares(void *);

void *sumsquares(void *val)
{
    int value = (intptr_t)val;
    int sumsquares = 0;
    for (int i = value; i > 0; i--)
    {
        sumsquares += i;
    }
    return sumsquares * sumsquares;
    sleep(rand());
    // pthread_exit(NULL);
}

void *sumcubes(void *val)
{
    int value = (intptr_t)val;
    int sumcubes = 0;
    for (int i = value; i > 0; i--)
    {
        sumcubes += (i * i * i);
    }
    return sumcubes;
    sleep(rand());
    // pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if (argc > 1)
    {
        pthread_t tid0;
        pthread_t tid1;
        void *squares;
        void *cubes;
        int number = atoi(argv[1]);

        int squarearray[number];
        int cubearray[number];
        for (int i = 0; i < number; i++)
        {
            int current = i + 1;
            int fail = pthread_create(&tid0, NULL, sumsquares, (void *)(intptr_t)current);
            if (fail)
            {
                printf("ERORR; return code from pthread_create() is %d\n", fail);
                exit(EXIT_FAILURE);
            }
            pthread_join(tid0, &squares);
            int fail2 = pthread_create(&tid1, NULL, sumcubes, (void *)(intptr_t)current);
            if (fail2)
            {
                printf("ERORR; return code from pthread_create() is %d\n", fail2);
                exit(EXIT_FAILURE);
            }
            pthread_join(tid1, &cubes);
            squarearray[i] = (int)squares;
            cubearray[i] = (int)cubes;
            printf("%d of %d checked\n", i + 1, number);
            sleep(0);
        }
        for (int i = 0; i < number; i++)
        {
            // printf("%d - squares: %d, cubes: %d\n", i+1, squarearray[i], cubearray[i]);
            if (squarearray[i] == cubearray[i])
            {
                printf("%d - %d\n", i + 1, squarearray[i]);
            }
        }

        pthread_exit(NULL);
    }
    else
        printf("Please add argument when running the program");
    return 0;
}
