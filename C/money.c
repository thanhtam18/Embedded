#include "stdio.h"
#include "stdint.h"

enum{
    TRAM,
    DONVI,
    CHUC
};

enum{
    DONG = 1,
    NGHIN = 4,
    TRIEU = 7,
    TY = 10
};

uint8_t size(const char string[]){
    uint8_t index = 0;
    while (*string++ != '\0')
        index++;
    return index;
}

void displayNumber(const char number[], uint8_t unit, uint8_t location){
    switch (number[location]){
    case '0':
        if (unit == TRAM)
            printf("Khong ");
        else if (unit == CHUC && number[location + 1] != '0')
            printf("Le ");
        break;
    case '1':
        if (unit == CHUC)
            printf("Muoi` ");
        else if (unit == DONVI && number[location - 1] != '1' && number[location - 1] != '0')
            printf("Mot' ");
        else
            printf("Mot. ");
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        if (unit == DONVI && number[location - 1] != '1' && number[location - 1] != '0')
            printf("Tu ");
        else
            printf("Bon ");
        break;
    case '5':
        if (unit == DONVI && number[location - 1] != '0')
            printf("Lam ");
        else
            printf("Nam ");      
        break;
    case '6':
        printf("Sau ");
        break;
    case '7':
        printf("Bay ");
        break;
    case '8':
        printf("Tam ");
        break;
    case '9':
        printf("Chin ");
        break;
    }
}

int main(int argc, char const *argv[]){
    char money[] = "124141654011"; //124 141 654 011
    uint8_t length = size(money);
    for (uint8_t i = 0; i < money[i] != '\0'; i++){
        uint8_t unit = (length - i) % 3;
        displayNumber(money, unit, i);
        switch (unit){
        case TRAM:
            printf("Tram ");
            break;
        case CHUC:
            if(money[i] != '0' && money[i] != '1')
                printf("Muoi ");
            break;
        case DONVI:
            uint8_t location = length - i;
            switch (location){
            case TY:
                printf("Ty ");
                break;
            case TRIEU:
                printf("Trieu ");
                break;
            case NGHIN:
                printf("Nghin ");
                break;
            case DONG:
                printf("Dong ");
                return 0;
                break;
            }
            uint8_t count = 0;
            uint8_t j = i + 1;
            while(money[j] != '\0'){
                if(money[j] != '0')
                    count++;
                j++;
            }
            if(count == 0){
                printf("Dong");
                return 0;
            }
            break;
        }
    }
    return 0;
}
