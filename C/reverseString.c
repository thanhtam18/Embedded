#include "stdio.h"
#include "stdint.h"

uint8_t sizeString(const char string[]){
    uint8_t index = 1;
    for(uint8_t i = 0; string[i] != '\0'; i++)
        if(string[i] == ' ')
            index++;            
    return index;
}

void reverseString(const char string[]){
    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t size = sizeString(string);
    char *array[size];
    while(*string != '\0'){
        if(*string == ' '){
            array[index] = string - count;
            index++;
            count = 0;
            string++;
        }
        count++;
        string++;
    }
    array[index] = string - count;
    for (int8_t i = size -1; i >= 0; i--)
    {
        while(*array[i] != '\0' && *array[i] != ' ')
            printf("%c",*array[i]++);
        printf(" ");
    }
    
}

int main(int argc, char const *argv[])
{
    char string[] = "nam hoang mai son nam trung hoang son nam";
    reverseString(string);
    return 0;
}
