#include "stdio.h"

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

int size(const char string[]){
    int index = 0;
    while (*string++ != '\0')
        index++;
    return index;
}

void displayNumber(const char number[], int unit, int location){
    switch (number[location]){
    case '0':
        if (unit == TRAM)
            printf("Không ");
        else if (unit == CHUC && number[location + 1] != '0')
            printf("Lẻ ");
        break;
    case '1':
        if (unit == CHUC)
            printf("Mười ");
        else if (unit == DONVI && number[location - 1] != '1' && number[location - 1] != '0' && location != 0)
            printf("Mốt ");
        else
            printf("Một ");
        break;
    case '2':
        printf("Hai ");
        break;
    case '3':
        printf("Ba ");
        break;
    case '4':
        if (unit == DONVI && number[location - 1] != '1' && number[location - 1] != '0' && location != 0)
            printf("Tư ");
        else
            printf("Bốn ");
        break;
    case '5':
        if (unit == DONVI && number[location - 1] != '0' && location != 0)
            printf("Lăm ");
        else
            printf("Năm ");      
        break;
    case '6':
        printf("Sáu ");
        break;
    case '7':
        printf("Bảy ");
        break;
    case '8':
        printf("Tám ");
        break;
    case '9':
        printf("Chín ");
        break;
    }
}

int main(int argc, char const *argv[]){

    char money[] = "150241023824"; // nhập số tiền  

    int length = size(money);   // tính số phần tử của mảng

    for (int i = 0; i < money[i] != '\0'; i++){
        /*Thuat Toan:
            (số phần tử - vị trí của phần tử trong mảng) % 3 = 0  : hàng trăm
            (số phần tử - vị trí của phần tử trong mảng) % 3 = 2  : hàng chục
            (số phần tử - vị trí của phần tử trong mảng) % 3 = 1  : hàng đơn vị
        */
        int unit = (length - i) % 3;
        displayNumber(money, unit, i);
        switch (unit){
        case TRAM:
            printf("Trăm ");
            break;
        case CHUC:
            if(money[i] != '0' && money[i] != '1')
                printf("Mươi ");
            break;
        case DONVI:
            /*Thuat Toan:
                số phần tử - vị trí của phần tử trong mảng = 10  : hàng tỷ
                số phần tử - vị trí của phần tử trong mảng = 7  : hàng triệu
                số phần tử - vị trí của phần tử trong mảng = 4  : hàng nghìn
                số phần tử - vị trí của phần tử trong mảng = 1  : hàng đồng
            */
            int location = length - i;
            switch (location){
            case TY:
                printf("Tỷ ");
                break;
            case TRIEU:
                printf("Triệu ");
                break;
            case NGHIN:
                printf("Nghìn ");
                break;
            case DONG:
                printf("Đồng ");
                return 0;  // kết thúc chương trình
                break;
            }
            int count = 0;
            int j = i + 1;
            while(money[j] != '\0'){
                if(money[j] != '0')
                    count++;
                j++;
            }
            if(count == 0){
                printf("Đồng");
                return 0;
            }
            break;
        }
    }
    return 0;
}
