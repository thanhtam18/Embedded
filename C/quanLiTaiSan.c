#include "stdio.h"
#include "stdlib.h"

typedef struct{
    char diaChi[10];
    double dienTich;    
}Nha;

typedef struct{
    char loaiXe[10];
    char bienSo[10];
}Xe;

typedef union{
    Nha thongTinNha;
    Xe  thongTinXe; 
}thongTin;

typedef enum{
    NHA,
    XE
}loaiTaiSan;

typedef struct{
    char maTaiSan[10];
    int giaTri;
    thongTin thongTinTaiSan;
}taiSan;    

void danhSachXe(taiSan *a){
    if(a->giaTri == XE)
        printf("Ma tai san: %s\tBien so: %s\tLoai Xe: %s\r\n", a->maTaiSan, a->thongTinTaiSan.thongTinXe.bienSo, a->thongTinTaiSan.thongTinXe.loaiXe);
}

void danhSachNha(taiSan *a){
    if(a->giaTri == NHA)
        printf("Ma tai san: %s\tDien tich: %0.2f\tDia chi: %s\r\n", a->maTaiSan, a->thongTinTaiSan.thongTinNha.dienTich, a->thongTinTaiSan.thongTinNha.diaChi);
}

void inDanhSach(taiSan list[], int n, void(*pFunction)(taiSan*)){
    for(int i = 0; i < n; i++){
        pFunction(list+i);
    }
}

int main(int argc, char const *argv[])
{
    taiSan danhSach[] = {
        {.maTaiSan = "GV1053", .giaTri = NHA, .thongTinTaiSan.thongTinNha.dienTich = 325.50 , .thongTinTaiSan.thongTinNha.diaChi = "Go Vap"},
        {.maTaiSan = "VT3520", .giaTri = XE, .thongTinTaiSan.thongTinXe.bienSo = "72K1-63630" , .thongTinTaiSan.thongTinXe.loaiXe = "Sirius"},
        {.maTaiSan = "TD9483", .giaTri = NHA, .thongTinTaiSan.thongTinNha.dienTich = 593.43 , .thongTinTaiSan.thongTinNha.diaChi = "Thu Duc"},
        {.maTaiSan = "TB0483", .giaTri = XE, .thongTinTaiSan.thongTinXe.bienSo = "59A1-89328" , .thongTinTaiSan.thongTinXe.loaiXe = "Wave"}
    };
    inDanhSach(danhSach,4,&danhSachNha);
    return 0;
}
