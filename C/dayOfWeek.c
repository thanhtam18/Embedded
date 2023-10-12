#include "stdio.h"
#include "stdint.h"

typedef struct
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}date;

const char *day[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

const date initDay ={1,1,2000};

date currentDay = {1,10,2100};

void dayCounter(date current){
    int8_t soNam = current.year - initDay.year;
    uint8_t soNamNhuan;
    for(uint8_t i = 0; i <= soNam; i++)
        if((i % 4 == 0 && i % 100 != 0) || (i % 100 == 0 && i % 400 == 0))
            soNamNhuan++;
    uint16_t days = (current.day-initDay.day) + 31*7*soNam + 30*4*soNam + 29*soNamNhuan + 28*(soNam-soNamNhuan);
        for(uint8_t i = 1; i < (current.month); i++){
            switch (i)
            {
            case 2:
                if((current.year % 4 == 0 && current.year % 100 != 0) || (current.year % 100 == 0 && current.year % 400 == 0))
                    days += 29;
                else
                    days += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days += 30;
                break;
            default:
                days += 31;
                break;
            }
        }
    printf("Today is %s",day[days%7]);
} 

int main(int argc, char const *argv[])
{
    dayCounter(currentDay);
    return 0;
}   
