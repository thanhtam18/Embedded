#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum{
    NAM,
    NU
}GioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}HocLuc;

typedef enum{
    TEN,
    MSSV,
    DIEM_TB
}SapXep;

class SinhVien{
    private:
        float monToan;
        float monLy;
        float monHoa;
        int maSoVinhVien;
        string tenSinhVien;
        int tuoiSinhVien;
        GioiTinh gioiTinhSinhVien;
    public:
        SinhVien(string ten = "", int tuoi = 0, GioiTinh gioiTinh = NAM, float toan = 0, float ly = 0, float hoa = 0) : 
                 tenSinhVien(ten), tuoiSinhVien(tuoi), gioiTinhSinhVien(gioiTinh),
                 monToan(toan), monHoa(hoa), monLy(ly){
                    static int id = 1000;
                    maSoVinhVien = id;
                    id++;
                 };

        void setTen(string ten);
        void setTuoi(int tuoi);
        void setGioiTinh(GioiTinh gt);
        void setDiemToan(float Toan);
        void setDiemLy(float Ly);
        void setDiemHoa(float Hoa);

        string getTenSV();
        GioiTinh getGioiTinh();
        int getTuoi();
        int getMSSV();
        float getDiemToan();
        float getDiemLy();
        float getDiemHoa();
        float getDiemTrungBinh();
        HocLuc getHocLuc();
};

void SinhVien :: setTen(string ten){
    this->tenSinhVien = ten;
}
void SinhVien :: setTuoi(int tuoi){
    this->tuoiSinhVien = tuoi;
}
void SinhVien :: setGioiTinh(GioiTinh gt){
    this->gioiTinhSinhVien = gt;
}
void SinhVien :: setDiemToan(float Toan){
    this->monToan = Toan;
}
void SinhVien :: setDiemLy(float Ly){
    this->monLy = Ly;
}
void SinhVien :: setDiemHoa(float Hoa){
    this->monHoa = Hoa;
}

string SinhVien :: getTenSV(){
    return tenSinhVien;
}
int SinhVien :: getTuoi(){
    return tuoiSinhVien;
}
GioiTinh SinhVien :: getGioiTinh(){
    return gioiTinhSinhVien;
}
int SinhVien :: getMSSV(){
    return maSoVinhVien;
}
float SinhVien :: getDiemToan(){
    return monToan;
}
float SinhVien :: getDiemLy(){
    return monLy;
}
float SinhVien :: getDiemHoa(){
    return monHoa;
}
float SinhVien :: getDiemTrungBinh(){
    return (monToan + monLy + monHoa)/3;
}
HocLuc SinhVien :: getHocLuc(){
    if(getDiemTrungBinh() >= 8)
        return GIOI;
    else if(getDiemTrungBinh() >= 7)
        return KHA;
    else if(getDiemTrungBinh() >= 5)
        return TRUNG_BINH;
    else
        return YEU;    
}

class Menu{
    private:
        list<SinhVien> dataBase;
    public:
        void themSinhVien(SinhVien sv);
        int xoaSinhVien(int mssv);
        int suaSinhVien(int mssv);
        list<SinhVien> danhSach();
        void sapXepSinhVien(SapXep type);
};

void Menu :: themSinhVien(SinhVien sv){
    dataBase.push_back(sv);
}
int Menu :: xoaSinhVien(int mssv){
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getMSSV() == mssv){
            dataBase.erase(item);
            return 1;
        }
    }
    return 0;
}
int Menu :: suaSinhVien(int mssv){
    for(list<SinhVien>::iterator item = dataBase.begin(); item != dataBase.end(); item++){
        if(item->getMSSV() == mssv){
            string tenSV;
            int tuoiSV, gioiTinh;
            GioiTinh gioiTinhSV;
            float diemToan, diemLy, diemHoa;
            cout<<"Nhap Ten Sinh Vien: ";
            cin>>tenSV;
            cout<<"Nhap Tuoi Sinh Vien: ";
            cin>>tuoiSV;
            cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu     Ban Chon: ";
            cin>>gioiTinh;
            gioiTinhSV = (GioiTinh)gioiTinh;
            cout<<"Nhap Diem Toan: ";
            cin>>diemToan;
            cout<<"Nhap Diem Ly: ";
            cin>>diemLy;
            cout<<"Nhap Diem Hoa: ";
            cin>>diemHoa;
            item->setTen(tenSV);
            item->setTuoi(tuoiSV);
            item->setGioiTinh(gioiTinhSV);
            item->setDiemToan(diemToan);
            item->setDiemLy(diemLy);
            item->setDiemHoa(diemHoa);
            return 1;
        }
    }
    return 0;    
}

void swap(list<SinhVien>::iterator a, list<SinhVien>::iterator b){
    SinhVien temp;
    temp = *a;
    *a = *b;
    *b = temp;  
}

int soSanhTen(string sinhVien1, string sinhVien2){
    int index = 0;
    while(sinhVien1[index] != '\0' && sinhVien2[index]!='\0' && sinhVien1[index] == sinhVien2[index]){
        index++;
    }
    return (int)sinhVien1[index] - (int)sinhVien2[index];
}

int soSanhTuoi(int sinhVien1, int sinhVien2){
    return sinhVien1 - sinhVien2;
}

float soSanhDiemTB(float sinhVien1, float sinhVien2){
    return sinhVien1 - sinhVien2;
}
void Menu :: sapXepSinhVien(SapXep type){
    switch (type)
    {
        case TEN:
            for(list<SinhVien>::iterator i = dataBase.begin(); i != dataBase.end(); i++){
                for(list<SinhVien>::iterator j = dataBase.begin(); j != dataBase.end(); j++){
                    if(soSanhTen(j->getTenSV(),i->getTenSV()) > 0)
                        swap(j,i);
                }
            }
            break;
        case MSSV:
            for(list<SinhVien>::iterator i = dataBase.begin(); i != dataBase.end(); i++){    
                for(list<SinhVien>::iterator j = dataBase.begin(); j != dataBase.end(); j++){
                    if(soSanhTuoi(j->getMSSV(),i->getMSSV()) > 0)
                        swap(j,i);
                }
            }
            break;
        case DIEM_TB:
            for(list<SinhVien>::iterator i = dataBase.begin(); i != dataBase.end(); i++){
                for(list<SinhVien>::iterator j = dataBase.begin(); j != dataBase.end(); j++){
                    if(soSanhDiemTB(j->getDiemTrungBinh(),i->getDiemTrungBinh()) > 0)
                        swap(j,i);
                }
            }
            break;
    }
}
list<SinhVien> Menu :: danhSach(){
    return dataBase;
}

void addSinhVien(Menu *mn){
    string tenSV;
    int tuoiSV, gioiTinh;
    GioiTinh gioiTinhSV;
    float diemToan, diemLy, diemHoa;
    cout<<"------ Them Sinh Vien ------"<<endl;
    cout<<"Nhap Ten Sinh Vien: ";
    cin>>tenSV;
    do{
    cout<<"Nhap Tuoi Sinh Vien: ";
    cin>>tuoiSV;
    }while(tuoiSV < 0 || tuoiSV > 100);
    do{
    cout<<"Nhap Gioi Tinh Sinh Vien:  0.Nam   1.Nu     Ban Chon: ";
    cin>>gioiTinh;
    }while(gioiTinh != 0 && gioiTinh != 1);
    gioiTinhSV = (GioiTinh)gioiTinh;
    do{
    cout<<"Nhap Diem Toan: ";
    cin>>diemToan;
    }while(diemToan < 0 || diemToan > 10);
    do{
    cout<<"Nhap Diem Ly: ";
    cin>>diemLy;
    }while(diemLy < 0 || diemLy > 10);
    do{
    cout<<"Nhap Diem Hoa: ";
    cin>>diemHoa;      
    }while(diemHoa < 0 || diemHoa > 10);
    SinhVien sv(tenSV, tuoiSV, gioiTinhSV, diemToan, diemLy, diemHoa);
    mn->themSinhVien(sv);
    cout<<"----------------------------"<<endl;
}

void removeSinhVien(Menu *mn){
    int mssv;
    cout<<"------ Xoa Sinh Vien ------"<<endl;
    cout<<"Nhap MSSV cua Sinh Vien muon xoa: ";
    cin>>mssv;
    (mn->xoaSinhVien(mssv)) ? cout<<"Xoa thanh cong"<<endl : cout<<"Xoa that bai"<<endl;
    cout<<"----------------------------"<<endl;
}

void editSinhVien(Menu *mn){
    cout<<"------ Sua Sinh Vien ------"<<endl;
    int mssv;
    cout<<"Nhap MSSV cua Sinh Vien muon sua: ";
    cin>>mssv;
    (mn->suaSinhVien(mssv)) ? cout<<"Sua thanh cong"<<endl : cout<<"Sua that bai"<<endl;
    cout<<"----------------------------"<<endl;
}

void sortSinhVien(Menu *mn){
    cout<<"------ Sap Xep Danh Sach ------"<<endl;
    int k;
    do{
    cout<<"Chon kieu sap xep:   0. Theo Ten     1. Theo MSSV     2. Theo Diem TB     Ban chon: ";
    cin>>k;
    }while(k != 0 && k != 1 && k != 2);
    SapXep type = (SapXep)k;
    mn->sapXepSinhVien(type);
    cout<<"----------------------------"<<endl;
}

void display(Menu mn){
    list<SinhVien> danhSach;
    danhSach = mn.danhSach();
    cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (auto item : danhSach){ 
        cout<<"Ten: "<<item.getTenSV();
        cout<<"\tTuoi: "<<item.getTuoi();
        cout<<"\tGioi Tinh: "<<((item.getGioiTinh() == NAM) ? "Nam  " : "Nu   ");
        cout<<"\tMSSV: "<<item.getMSSV();
        cout<<"\tDiem Toan: "<<item.getDiemToan();
        cout<<"\tDiem Ly: "<<item.getDiemLy();
        cout<<"\tDiem Hoa: "<<item.getDiemHoa();
        cout<<"\tDiem TB: "<<item.getDiemTrungBinh()<<endl;
    }
    cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
}   

int main(int argc, char const *argv[])
{
    int key;
    Menu menu;
    while(1){
        cout<<"------Menu------"<<endl;
        cout<<"1. Them Sinh Vien"<<endl;
        cout<<"2. Xoa Sinh Vien"<<endl;
        cout<<"3. Sua Sinh Vien"<<endl;
        cout<<"4. In Danh Sach Sinh Vien"<<endl;
        cout<<"5. Sap Xep Danh Sach Sinh Vien"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Ban chon: ";
        cin>>key;
        switch(key){
            case 1:
                addSinhVien(&menu);
                break;
            case 2:
                removeSinhVien(&menu);
                break;
            case 3:
                editSinhVien(&menu);
                break;
            case 4:
                display(menu);
                break;
            case 5:
                sortSinhVien(&menu);
                break;
            case 0:
                return 0;
            default:
                cout<<"Chon khong hop le"<<endl;
        }
    }
    return 0;
}
