#include <stdio.h>
#include "stdlib.h"
#define USD 1
#define EUR 2
#define VND 3

typedef union{
    double usd;
    double eur;
    double vnd;
}roomPrice;

typedef enum{
    SINGLE,
    DOUBLE
}roomType;

typedef enum{
    EMPTY,
    BOOKED
}roomStatus;

typedef struct{
    int roomNumber;
    roomType type;
    roomPrice prices;
    roomStatus status;
    int currencyType;
}room;

double getPrices(room *Room){
    switch (Room->currencyType){
    case USD:
        if(Room->type == SINGLE)
            return Room->prices.usd = 1000;
        else if(Room->type == DOUBLE)
            return Room->prices.usd = 1500;
    case EUR:
        if(Room->type == SINGLE)
            return Room->prices.eur = 1300;
        else if(Room->type == DOUBLE)
            return Room->prices.usd = 1800;
    case VND:
        if(Room->type == SINGLE)
            return Room->prices.vnd = 500;
        else if(Room->type == DOUBLE)
            return Room->prices.usd = 1000;
    }
}

void roomCurrent(room array[], int quantity){
    printf("\r\nSo phong:");
    for (int i = 0; i < quantity; i++){
        array[i].roomNumber = i + 1;
        printf("\t%d",i+1);
    }
    printf("\r\n");
    printf("Trang thai:");
    for (int i = 0; i < quantity; i++){
        if(array[i].status == BOOKED)
        printf("\tx");
        else
        printf("\to");
    }
    printf("\r\n\n\r");
}

void roomConsoleLog(room array[], int quantity){
    printf("-----------------------\r\n");
    for(int i = 0; i < quantity; i++){
        if(array[i].status == BOOKED){
            printf("Ban da chon phong: ");
            printf("%2d\r\n", i+1);
        }
        else
            continue;
        if(array[i].type == SINGLE)
            printf("Loai phong: Don\r\n");
        else 
            printf("Loai phong: Doi\r\n");
        if(array[i].currencyType == USD)
            printf("USD: %0.2f\r\n",getPrices(&array[i]));
        else if(array[i].currencyType == EUR)
            printf("EUR: %0.2f\r\n",getPrices(&array[i]));
        else
            printf("VND: %0.2f\r\n",getPrices(&array[i]));  
        printf("-----------------------\r\n");
    }
}

void total(room array[], int quantity){
    double sumUSD = 0;
    double sumEUR = 0;
    double sumVND = 0;
    for(int i = 0; i < quantity; i++){
        if(array[i].status == BOOKED){
            if(array[i].currencyType == USD)
                sumUSD += array[i].prices.usd;
            else if(array[i].currencyType == EUR)
                sumEUR += array[i].prices.usd;
            else
                sumVND += array[i].prices.usd;
        }
        else
            continue;
    }
    printf("Tong USD: %0.2f\r\n", sumUSD);
    printf("Tong EUR: %0.2f\r\n", sumEUR);
    printf("Tong VND: %0.2f\r\n", sumVND);
}

int main(int argc, char const *argv[])
{
    int roomQuantity;
    do{
    printf("Nhap so luong phong: ");
    scanf("%d",&roomQuantity);
    }while(roomQuantity <= 0);
    room *arr = (room *)malloc(sizeof(room)*roomQuantity);
    void (*function[]) (room*, int) = {&roomCurrent, &roomConsoleLog, &total};
    for (int i = 0; i < roomQuantity; i++){
        arr[i].status = EMPTY;
    }
    function[0](arr, roomQuantity);
    while (1){    
        int number;
        int type; 
        int currency;
        do{
            printf("Chon phong: ");
            scanf("%d",&number);
        }while(number > roomQuantity || number <= 0);
        if(arr[number-1].status == BOOKED){
            printf("Phong %d da duoc thue, moi chon phong khac\r\n",number);
            continue;
        }  
        else
            arr[number-1].status = BOOKED;
        printf("Loai phong: \t1. Don\t2. Doi\r\n");
        do{
        printf("Chon loai phong: ");
        scanf("%d",&type);
        }while(type != 1 && type != 2);
        if(type == 1)
            arr[number-1].type = SINGLE;
        else
            arr[number-1].type = DOUBLE;
        printf("Don vi tien: \t1. USD\t2. EUR\t3. VND\r\n");
        do{
        printf("Chon loai: ");
        scanf("%d",&arr[number-1].currencyType);
        }while(arr[number-1].currencyType != 1 && arr[number-1].currencyType != 2 && arr[number-1].currencyType != 3);
        function[1](arr, roomQuantity);
        function[2](arr, roomQuantity);
        function[0](arr, roomQuantity);   
    }
    free(arr);
    return 0;
}
