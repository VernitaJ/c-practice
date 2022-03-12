#include <stdio.h>

const int MAX = 3;

void pointerVariables();
void pointerVariablesToo();
void pointerArray();
void pointerStrings();

int main()
{
    pointerVariables();
    pointerVariablesToo();
    pointerArray();
    pointerStrings();

    return 0;
}

void pointerVariables()
{
    int var = 20; /* actual variable declaration */
    int *ip;      /* pointer variable declaration */
    
    ip = &var; /* store address of var in pointer variable*/

    printf("Address of var variable: %x\n", &var);
    /* address stored in pointer variable */
    printf("Address stored in ip variable: %x\n", ip);
    /* access the value using the pointer */
    printf("Value of *ip variable: %d\n", *ip);

    int arr[] = {10, 20, 40, 80};
    int *ptr;

    ptr = arr;
    for (int i = 0; i < 4; i++)
    {
        printf("Address of var[%d] = %x\n", i, ptr);
        printf("Value of var[%d] = %d\n", i, *ptr);
        /* move to the next location */
        ptr++;
    }
}

void pointerVariablesToo()
{
    int arr[] = {10, 20, 40, 80};
    int *ptr;
    
    ptr = arr;
    int i = 0;
    while (ptr <= &arr[3])
    {
        printf("Address of var[%d] = %x\n", i, ptr);
        printf("Value of var[%d] = %d\n", i, *ptr);

        /* move to the next location */
        ptr++;
        i++;
    }
}

void pointerArray()
{
    int var[] = {10, 100, 200};
    int i, *ptr[MAX];

    for (i = 0; i < MAX; i++)
    {
        ptr[i] = &var[i]; /* assign the address of integer. */
    }

    for (i = 0; i < MAX; i++)
    {
        printf("Value of var[%d] = %d\n", i, *ptr[i]);
    }

    return 0;
}

void pointerStrings()
{
    char *names[] = {
      "Theo Ali",
      "Ali Booster",
      "Nala Lala"
   };
   
   int i = 0;

   for ( i = 0; i < MAX; i++) {
      printf("Value of names[%d] = %s\n", i, names[i] );
   }
   
   return 0;
}