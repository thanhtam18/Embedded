#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"

typedef struct
{
    char *ptr;
    uint8_t length;
    uint8_t quantity;
    bool status;
}words;

uint8_t sizeString(const char string[]){
    uint8_t index = 1;
    for(uint8_t i = 0; string[i] != '\0'; i++)
        if(string[i] == ' ')
            index++;            
    return index;
}

void splitString(const char string[], words array[]){
    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t i = 0;
    while ( *string != '\0')
    {
        if( *string == ' '){
            array[index].ptr = string - count;
            array[index].length = count;
            string++;
            index++;
            count = 0;
        }
        else{
            string++;
            count++;
        }
    }
    array[index].ptr = string - count;
    array[index].length = count;
}

void findName(words array[], uint8_t size){
    for (uint8_t i = 0; i < size; i++)
    {
        uint8_t count = 0;
        for (uint8_t j = 0; j < size; j++){
            uint8_t index = 0;
            while(array[i].ptr[index] == array[j].ptr[index]){
                index++;
                if(array[i].length == index && array[j].length == index){
                    count++;
                    if(count >= 2)
                        array[j].status = false;
                    else
                        array[j].status = true;
                    break;
                }
            }
        }
        array[i].quantity = count;
    }   
}

void display(words arr[], uint8_t size){
    for (uint8_t i = 0; i < size; i++)
    {
        if(arr[i].status == true)        
        {
            for (uint8_t j = 0; j < arr[i].length; j++)
            {
                printf("%c",arr[i].ptr[j]);
            }
            printf("\t%d\r\n",arr[i].quantity);
        }
    }  
}

int main(int argc, char const *argv[])
{
    char string[] = "nam hoang mai son nam trung hoang son nam";
    uint8_t size = sizeString(string);
    words array[size];
    splitString(string,array);
    findName(array,size);
    display(array,size);
    return 0;
}
