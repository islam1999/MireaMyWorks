#include <stdio.h>
#include <stdlib.h>

char *weeks[] ={
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

typedef struct struct_date{
    int day;
    int month;
    int year;
} struct_date;

int what_day(const struct struct_date* date){
    int a = (14 - date->month) / 12;
    int y = date->year - a;
    int m = date->month + 12 * a - 2;
    return (7000 + (date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
}

int CurrentDay(){
    struct_date date;

    printf("\nDay: ");
    scanf("%d", &date.day);

    printf("\nMonth:");
    scanf("%d", &date.month);

    printf("\nYear:");
    scanf("%d", &date.year);

    int d;
    if(date.month > 0 && date.month <13){
        if(date.day > 0 && date.day < 32){
            if(date.day>30 && date.month == 2){    
               return -1;
            }
            d =  what_day(&date);
            printf("\n%s", weeks[d]);
        }
    }
    return -1;
}
