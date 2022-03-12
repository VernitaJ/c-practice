// when casting structs, can only pass to struct that has less variables.
// ie - struct sPerson* sPerson = (sPerson *) sCompletePerson
// this is because we can't cast a struct with more elements as it would take memory space from another element in the program.
#include <stdio.h>

int main() 
{
    int *p = 10;
    int* q = 10;
    printf("p value - %d", p); // prints value of p
    printf("p address - %d", &p); // prints value of p
    int* value = &p;
    int* point = p; 
    printf("p value - %d", value); // prints value of p
    printf("p address - %d", point); // prints value of p

    // printf("p pointer - %d", *p);
}