#include <stdio.h>
#include <stdbool.h>

void getDay(int, int, int);

int main(int argc, char const *argv[])
{
    getDay(9, 3, 2022);
    return 0;
}

void getDay(int day, int month, int year)
{
    bool leap = 0;
    int whichDay = 0;
    if (year % 4 == 0){
        leap = 1;
    }
    for (int i = month; i > 1; i--) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
            whichDay+=31;
        } else if (i == 2){
            if (leap) {
                whichDay+=29;
            } else day+=28;
        } else whichDay+=30;
    }
    whichDay+=day;
    printf("Day is: %d", whichDay);
}