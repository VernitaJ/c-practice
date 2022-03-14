/*
Question 3: Multithreaded elevator – 8 points
Create a multithreaded elevator program. The main thread should be responsible for the interaction
between the user and the elevator. The child thread should control the elevator’s movement.
The elevator should move between 0 and MAX floors (MAX is defined by you, should be between 10
and 20). The travel time between each floor is 1 second. When the elevator reaches the desired
floor, a message is printed on the console. When the elevator moves between the floors, a message
with the elevator’s position should be printed to the console when passing a floor and once in￾between every floor.
The user can choose the floor where he/she wants to travel only when the elevator is waiting at one
of the floors. When the user chooses a new floor while the elevator is in motion (moving to the
destination floor), an error message should be printed.
The user can always choose to print the status of the elevator. The output of the status should be:
waiting_for_user or moving. */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> //header imported to use the random function and malloc
#include <time.h>   //header imported to use the random function

#define MAX 20

void *elevator(void *param);
void *movement(void *);
int acquireFloor(int min, int m);
void clear_stdin();

pthread_mutex_t movingSem = PTHREAD_MUTEX_INITIALIZER;
int currentFloor = 0;
int destination = 0;
int moving = 0;

int main()
{
    pthread_t thread;
    if (pthread_create(&thread, NULL, movement, NULL))
    {
        printf("error creating thread\n");
        return -1;
    }

    printf("-1 : print status \n 0-%d: to select a floor\n\n", MAX);

    while (1)
    {
        int input; // prints user prompt for input to console
        scanf("%d", &input);
        pthread_mutex_lock(&movingSem);
        if (input == -1)
        {
            if (moving)
            {
                printf("\nstatus: Moving");
            }
            else
                printf("\nstatus: waiting for user input");
        }
        else if (input >= 0 && input <= MAX)
        {
            if (moving == 1)
            {
                printf("\nthe elevator is already moving");
            }
            else
            {
                moving = 1;
                destination = input;
            }
        }
        else
            printf("\nIncorrect input, try again");
        pthread_mutex_unlock(&movingSem);
    }
    pthread_join(thread, NULL);
}

void *movement(void *param)
{
    while (1)
    {
        pthread_mutex_lock(&movingSem);
        if (moving)
        {
            printf("\nCurrent floor:%d", currentFloor);
            if (destination > currentFloor)
            {
                currentFloor++;
            }
            else if (destination < currentFloor)
            {
                currentFloor--;
            }
            else
            {
                printf("\nArrived\n");
                moving = 0;
            }
        }
        pthread_mutex_unlock(&movingSem);
        sleep(1);
    }

    pthread_exit(NULL);
}

// // the following function is from my group (2), IT WAS ALSO ORIGINALLY WRITTEN BY ME IN ONE OF THE LABS (one of the first labs, i don't remember which).
// // what it does it's just safely acquire a value between min and max, if this is considered plagmarism, a scanf does the same as this function it's does not check the values though
// int acquireFloor(int min, int m)
// {

//     int inputVal; // acquired val

//     char endLine;       // to check if the value insered is actually an integer
//     int wrongInput = 0; // a 'boolean' value to keep track of the (wrong) user input

//     do
//     {
//         // the input is not yet wrong
//         wrongInput = 0;
//         // asking the user to insert a value

//         // acquiring the user answer inputVal, and also acquiring a new line character to make sure an integer is insered
//         if (scanf("%d%c", &inputVal, &endLine) != 2 || endLine != '\n')
//         {
//             // clean the input buffer after reading the input
//             clear_stdin();
//             // printing an error message to the user
//             perror("\n**ERROR: unexpected value in input**\n");
//             // the value insered is not correct, so wrongInput=1;
//             wrongInput = 1;
//         }

//         // the user is asked to insert a coordinate value untill it's a value between min and max (and it's a number, the last condition in the do-while guard checks this)
//     } while ((inputVal > m || inputVal < min) || wrongInput == 1);

//     // returning the value read
//     return inputVal;
// }
// // to clear the stdin buffer since fflush on unix doesn't work
// void clear_stdin()
// {
//     //'moving' forward the pointer related with the stdin buffer, until \n
//     while (getchar() != '\n')
//     {
//         ;
//     }
// }