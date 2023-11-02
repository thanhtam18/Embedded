#include <iostream>
#include <string>
#include <vector>

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
        vector<SinhVien> dataBase;
    public:
        void themSinhVien(SinhVien sv);
        int xoaSinhVien(int mssv);
        int suaSinhVien(int mssv);
        vector<SinhVien> danhSach();
        void sapXepSinhVien(SapXep type);
};

void Menu :: themSinhVien(SinhVien sv){
    dataBase.push_back(sv);
}
int Menu :: xoaSinhVien(int mssv){
    for(int i = 0; i < dataBase.size(); i++){
        if(dataBase[i].getMSSV() == mssv){
            dataBase.erase(dataBase.begin()+i);
            return 1;
        }
    }
    return 0;
}
int Menu :: suaSinhVien(int mssv){
    for(int i = 0; i < dataBase.size(); i++){
        if(dataBase[i].getMSSV() == mssv){
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
            dataBase[i].setTen(tenSV);
            dataBase[i].setTuoi(tuoiSV);
            dataBase[i].setGioiTinh(gioiTinhSV);
            dataBase[i].setDiemToan(diemToan);
            dataBase[i].setDiemLy(diemLy);
            dataBase[i].setDiemHoa(diemHoa);
            return 1;
        }
    }
    return 0;    
} 
vector<SinhVien> Menu :: danhSach(){
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

void display(Menu mn){
    vector<SinhVien> danhSach;
    danhSach = mn.danhSach();
    cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < danhSach.size(); i++){ 
        cout<<"Ten: "<<danhSach[i].getTenSV();
        cout<<"\tTuoi: "<<danhSach[i].getTuoi();
        cout<<"\tGioi Tinh: "<<((danhSach[i].getGioiTinh() == NAM) ? "Nam  " : "Nu   ");
        cout<<"\tMSSV: "<<danhSach[i].getMSSV();
        cout<<"\tDiem Toan: "<<danhSach[i].getDiemToan();
        cout<<"\tDiem Ly: "<<danhSach[i].getDiemLy();
        cout<<"\tDiem Hoa: "<<danhSach[i].getDiemHoa();
        cout<<"\tDiem TB: "<<danhSach[i].getDiemTrungBinh()<<endl;
    }
    cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
}   

int main(int argc, char const *argv[])
{
    int key;
    Menu menu;
    do{
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
        }
    }while(key != 0);
    return 0;
}
