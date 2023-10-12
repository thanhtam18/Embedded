#include "stdio.h"
#include "stdlib.h"

typedef union{
    char xepLoai;
}xeploai;

typedef struct{
    char ten[10];
    int maSo;
    double diem;
    xeploai diemChu;
}sinhvien;

char xepLoai(sinhvien *sv){
    if(sv->diem >= 9.0)
        return sv->diemChu.xepLoai = 'A';
    else if(sv->diem >= 8.0)
        return sv->diemChu.xepLoai = 'B';
    else if(sv->diem >= 7.0)
        return sv->diemChu.xepLoai = 'C';
    else if(sv->diem >= 6.0)
        return sv->diemChu.xepLoai = 'D';
    else if(sv->diem >= 5.0)
        return sv->diemChu.xepLoai = 'E';
    else if(sv->diem < 5.0)
        return sv->diemChu.xepLoai = 'F';
}

void consoleLog(sinhvien sv[], int quantity){
    for (int i = 0; i < quantity; i++){
        int index = 0;
        printf("%d. ",i+1);
        printf("%s\t",sv[i].ten);
        while(sv[i].ten[index] != '\0')
            index++;
        if(index < 5)
            printf("\t");
        printf("%d\t%0.1f\t%c",sv[i].maSo,sv[i].diem,xepLoai(&sv[i]));
        printf("\r\n");
    }
}

void xepTheoTen(sinhvien sv[], int quantity){
    for (int i = 0; i < quantity - 1; i++)
    {
        for(int j = 0; j < quantity - i - 1; j++){
            if(sv[j].ten[0] > sv[j+1].ten[0]){
                sinhvien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
            }
            else if(sv[j].ten[0] == sv[j+1].ten[0]){
                int index = 1;
                while(sv[j].ten[index] !='\0' && sv[j+1].ten[index] !='\0'){
                    if(sv[j].ten[index] > sv[j+1].ten[index]){
                        sinhvien temp = sv[j];
                        sv[j] = sv[j+1];
                        sv[j+1] = temp;
                    }
                    index++;
                }
            }
        }
    }
    consoleLog(sv,quantity);
}

void xepTheoDiem(sinhvien sv[], int quantity){
    for (int i = 0; i < quantity - 1; i++)
    {
        for(int j = 0; j < quantity - i - 1; j++){
            if(sv[j].diem > sv[j+1].diem){
                sinhvien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
            }
        }
    }
    consoleLog(sv,quantity); 
}

void xepTheoMSSV(sinhvien sv[], int quantity){
    for (int i = 0; i < quantity - 1; i++)
    {
        for(int j = 0; j < quantity - i - 1; j++){
            if(sv[j].maSo > sv[j+1].maSo){
                sinhvien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
            }
        }
    }
    consoleLog(sv,quantity);
}

int main(int argc, char const *argv[])  
{
    int quantity;
    int type;
    do{
        printf("Nhap so luong sinh vien: ");
        scanf("%d",&quantity);
    }while(quantity <= 0);
    sinhvien *sv = (sinhvien*)malloc(sizeof(sinhvien)*quantity);
    void (*funtion[])(sinhvien*,int) = {&xepTheoTen, &xepTheoDiem, &xepTheoMSSV};
    for(int i = 0; i < quantity; i++){
        printf("Nhap Ten sinh vien thu %d: ",i+1);
        scanf("%s",&sv[i].ten);
        printf("Nhap MSSV thu %d: ",i+1);
        scanf("%d",&sv[i].maSo);
        do{
        printf("Nhap Diem thu %d: ",i+1);
        scanf("%lf",&sv[i].diem);
        }while(sv[i].diem < 0 || sv[i].diem > 10);
    }
    while(1){
    do{
    printf("\r\nSap xep danh sach:\t1. Theo Ten\t2. Theo Diem\t3. Theo MSSV\tChon: ");
    scanf("%d",&type);
    }while(type != 1 && type != 2 && type != 3);
    printf("\r\nTen\t\tMSSV\tDiem\tXep Loai\r\n");
    funtion[type-1](sv,quantity);
    }
    free(sv);
    return 0;
}
