#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

typedef enum{
    THUC_AN,
    THUC_UONG
}LoaiDoAn;

typedef enum{
    PHA_CHE,
    PHUC_VU
}ViTriLamViec;

typedef enum{
    CA_SANG,
    CA_CHIEU
}ThoiGianLamViec;

typedef enum{
    THEO_GIA = 1,
    THEO_THUC_AN,
    THEO_THUC_UONG
}SapXepDoAn;

typedef enum{
    THEO_TEN = 1,
    THEO_TUOI,
    THEO_ID
}SapXepNV;

class DoAn{
    private:
        string Id;
        string Ten;
        LoaiDoAn Loai;
        float Gia;
    public:
        DoAn(string ten, LoaiDoAn loai, float gia);
        void setGia(float gia);
        string getId();
        string getTen();
        LoaiDoAn getLoai();
        float getGia();
};
DoAn :: DoAn(string ten, LoaiDoAn loai, float gia){
    this->Ten = ten;
    this->Loai = loai;
    this->Gia = gia;
    static int idThucAn = 100;
    static int idThucUong = 100;
    switch (loai){
        case THUC_AN:
            Id = "TA" + to_string(idThucAn);
            idThucAn++;
            break;
        case THUC_UONG:
            Id = "TU" + to_string(idThucUong);
            idThucUong++;
            break;
    }
}
void DoAn :: setGia(float gia){
    this->Gia = gia;
}
string DoAn :: getId(){
    return Id;
}
string DoAn :: getTen(){
    return Ten;
}
LoaiDoAn DoAn :: getLoai(){
    return Loai;
}
float DoAn :: getGia(){
    return Gia;
}

class ThongTinNhanVien{
    private:
        string tenNV;
        string idNV;
        int tuoiNV;
        ViTriLamViec viTriNV;
        ThoiGianLamViec thoiGian;
    public:
        ThongTinNhanVien(string ten, int tuoi, ViTriLamViec vt, ThoiGianLamViec tg);
        string getTen();
        string getId();
        int getTuoi();
        ViTriLamViec getViTri();
        ThoiGianLamViec getThoiGian();
};
ThongTinNhanVien :: ThongTinNhanVien(string ten, int tuoi, ViTriLamViec vt, ThoiGianLamViec tg){
    tenNV = ten; 
    tuoiNV = tuoi;
    viTriNV = vt;
    thoiGian = tg;
    static int id = 100;
    idNV = "NV" + to_string(id);
    id++;
}
string ThongTinNhanVien :: getTen(){
    return tenNV;
}
string ThongTinNhanVien :: getId(){
    return idNV;
}
int ThongTinNhanVien ::getTuoi(){
    return tuoiNV;
}
ViTriLamViec ThongTinNhanVien :: getViTri(){
    return viTriNV;
}
ThoiGianLamViec ThongTinNhanVien :: getThoiGian(){
    return thoiGian;
}

class QuanLy{
    private:
        list<DoAn> *dataBaseDoAn;
        list<ThongTinNhanVien> dataBaseNV;
        int *soLuongBan;
        void themDoAn();
        void suaDoAn();
        void xoaDoAn();
        void displayDoAn();
        void danhSachMonAn(SapXepDoAn type);
        void themNV();
        void xoaNV();
        void displayNV();
        void danhSachNV(SapXepNV type);
    public:
        QuanLy(list<DoAn> *listDoAn, int *soLuong){
            dataBaseDoAn = listDoAn;
            soLuongBan = soLuong;
        }
        void setSoLuongBan();
        void quanLyMonAn();
        void quanLyNhanVien();
        void testListNV();
};

void QuanLy :: setSoLuongBan(){
    int soLuong;
    cout<<"Set up so luong ban"<<endl;
    do{
        cout<<"Vui long nhap so luong ban: ";
        cin>>soLuong;
    }while(soLuong <= 0);
    cout<<"--------------------------------"<<endl;
    cout<<"So luong ban la: "<<soLuong<<endl;
    *soLuongBan = soLuong;
}

void QuanLy :: themDoAn(){
    string ten;
    int type;
    LoaiDoAn loai;
    float gia;
    cout<<"Them mon"<<endl;
    cout<<"Nhap ten mon: ";
    cin.ignore();
    getline(cin, ten);
    do{
        cout<<"Thuc an/Thuc uong (0/1): ";
        cin>>type;
    }while(type != 0 && type != 1);
    loai = (LoaiDoAn)type;
    do{
        cout<<"Gia: ";
        cin>>gia;
    }while(gia <= 0);
    DoAn da(ten, loai, gia);
    dataBaseDoAn->push_back(da);
    cout<<"------------------------------------"<<endl;  
    cout<<"ID\tTen\tLoai\tGia"<<endl;
    cout<<da.getId();
    cout<<"\t"<<da.getTen();
    cout<<"\t"<<((da.getLoai() == THUC_AN) ? "TA" : "TU");
    cout<<"\t"<<da.getGia()<<endl;
    cout<<"------------------------------------"<<endl;  
};

void QuanLy :: displayDoAn(){
    cout<<"------------------------------------"<<endl;
    cout<<"ID\tTen\tLoai\tGia"<<endl;
    for(list<DoAn>::iterator i = dataBaseDoAn->begin(); i != dataBaseDoAn->end(); i++){
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<((i->getLoai() == THUC_AN) ? "TA" : "TU");
            cout<<"\t"<<i->getGia()<<endl;     
    }
    cout<<"------------------------------------"<<endl;  
}

bool compareID(string item1, string item2){
    int index = 0;
    int length = 0;
    while(item2[length] != '\0')
        length++;
    while(item1[index] != '\0' && item2[index] != '\0' && item1[index] == item2[index]){
        index++;
    }
    if(index == length)
        return true;
    else
        return false;
}

void QuanLy :: suaDoAn(){
    string id;
    displayDoAn();
    cout<<"Vui long nhap ID: ";
    cin>>id;
    for(list<DoAn>::iterator i = dataBaseDoAn->begin(); i != dataBaseDoAn->end(); i++){
        if(compareID(i->getId(),id)){
            cout<<"ID\tTen\tLoai\tGia"<<endl;
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<((i->getLoai() == THUC_AN) ? "TA" : "TU");
            cout<<"\t"<<i->getGia()<<endl;
            cout<<"------------------------------------"<<endl;  
            float prices;
            do{
                cout<<"Vui long nhap gia moi: ";
                cin>>prices;
            }while(prices < 0);
            i->setGia(prices);
            cout<<"Gia moi la: "<<i->getGia()<<endl;
            return;
        }
    }
    cout<<"Sua that bai"<<endl;  
}

void QuanLy :: xoaDoAn(){
    string id;
    displayDoAn();
    cout<<"Vui long nhap ID: ";
    cin>>id;
    for(list<DoAn>::iterator i = dataBaseDoAn->begin(); i != dataBaseDoAn->end(); i++){
        if(compareID(i->getId(),id)){
            cout<<"ID\tTen\tLoai\tGia"<<endl;
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<((i->getLoai() == THUC_AN) ? "TA" : "TU");
            cout<<"\t"<<i->getGia()<<endl;
            cout<<"------------------------------------"<<endl;  
            int key;
            do{
                cout<<"1. Xac nhan xoa"<<endl;
                cout<<"0. Huy"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1){
                dataBaseDoAn->erase(i);
                cout<<"Xoa thanh cong"<<endl;
            }
                return;          
        }
    }
    cout<<"Xoa that bai"<<endl;     
}

void QuanLy :: quanLyMonAn(){
    int key;
LABEL3:
    do{
        cout<<"Set up mon an/thuc uong"<<endl;
        cout<<"1. Them mon"<<endl;
        cout<<"2. Sua mon"<<endl;
        cout<<"3. Xoa mon"<<endl;
        cout<<"4. Danh sach mon"<<endl;
        cout<<"0. Quay lai"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key < 0 || key > 4);
    switch (key){
        case 1:
LABEL4:
            themDoAn();
            do{
                cout<<"1. Them mon moi"<<endl;
                cout<<"0. Quay lai"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1)
                goto LABEL4;
            else 
                goto LABEL3;
        case 2:
            suaDoAn();
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL3;
        case 3:
            xoaDoAn();
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL3;
        case 4:
LABEL5:
            do{
                cout<<"1. Loc theo gia"<<endl;
                cout<<"2. Loc theo mon an"<<endl;
                cout<<"3. Loc theo thuc uong"<<endl;
                cout<<"0. Quay lai"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key < 0 || key > 3);
            if(key == 0)
                goto LABEL3;
            else{
                SapXepDoAn type = (SapXepDoAn)key;
                danhSachMonAn(type);
            }
            goto LABEL5;
    }
}

void QuanLy :: themNV(){
    string ten;
    int tuoi, viTri, thoiGian;
    ViTriLamViec vt;
    ThoiGianLamViec tg;
    cout<<"Them Nhan Vien"<<endl;
    cout<<"Nhap Ten Nhan Vien: ";
    cin.ignore();
    getline(cin, ten);
    cout<<"Nhap Tuoi Nhan Vien: ";
    cin>>tuoi;
    cout<<"Vi Tri (0. Pha Che/1. Phuc Vu): ";
    cin>>viTri;
    vt = (ViTriLamViec)viTri;
    cout<<"Thoi gian (0. Ca Sang/1. Ca Chieu): ";
    cin>>thoiGian;
    tg = (ThoiGianLamViec)thoiGian;
    ThongTinNhanVien nv(ten, tuoi, vt, tg);
    dataBaseNV.push_back(nv);
    cout<<"------------------------------------"<<endl; 
    cout<<"ID\tTen\tTuoi\tVi Tri\tCa"<<endl;
    cout<<nv.getId();
    cout<<"\t"<<nv.getTen();
    cout<<"\t"<<nv.getTuoi();
    cout<<"\t"<<((nv.getViTri() == PHA_CHE) ? "Pha Che" : "Phuc Vu");
    cout<<"\t"<<((nv.getThoiGian() == CA_SANG) ? "Ca Sang" : "Ca Chieu")<<endl;
    cout<<"------------------------------------"<<endl; 
}

void QuanLy :: displayNV(){
    cout<<"------------------------------------"<<endl;
    cout<<"ID\tTen\tTuoi\tVi Tri\tCa"<<endl;
    for(list<ThongTinNhanVien>::iterator i = dataBaseNV.begin(); i != dataBaseNV.end(); i++){
        cout<<i->getId();
        cout<<"\t"<<i->getTen();
        cout<<"\t"<<i->getTuoi();
        cout<<"\t"<<((i->getViTri() == PHA_CHE) ? "Pha Che" : "Phuc Vu");
        cout<<"\t"<<((i->getThoiGian() == CA_SANG) ? "Ca Sang" : "Ca Chieu")<<endl; 
    }
    cout<<"------------------------------------"<<endl; 
}

void QuanLy :: xoaNV(){
    displayNV();
    string id;
    cout<<"Vui long nhap ID: ";
    cin>>id;
    for(list<ThongTinNhanVien>::iterator i = dataBaseNV.begin(); i != dataBaseNV.end(); i++){
        if(compareID(i->getId(),id)){
            cout<<"ID\tTen\tTuoi\tVi Tri\tCa"<<endl;
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<i->getTuoi();
            cout<<"\t"<<((i->getViTri() == PHA_CHE) ? "Pha Che" : "Phuc Vu");
            cout<<"\t"<<((i->getThoiGian() == CA_SANG) ? "Ca Sang" : "Ca Chieu")<<endl;
            cout<<"------------------------------------"<<endl;  
            int key;
            do{
                cout<<"1. Xac nhan xoa"<<endl;
                cout<<"0. Huy"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1){
                dataBaseNV.erase(i);
                cout<<"Xoa thanh cong"<<endl;
            }   
            return;  
        }
    }
    cout<<"Xoa that bai"<<endl;  
}

int sortTen(list<ThongTinNhanVien>::iterator item1, list<ThongTinNhanVien>::iterator item2){
    int index = 0;
    while(item1->getTen()[index] != '\0' && item2->getTen()[index] != '\0' && item1->getTen()[index] == item2->getTen()[index]){
        index++;
    }
    return (int)item1->getTen()[index] - (int)item2->getTen()[index];
}

int sortTuoi(list<ThongTinNhanVien>::iterator item1, list<ThongTinNhanVien>::iterator item2){
    return item1->getTuoi() - item2->getTuoi();
}

int sortID(list<ThongTinNhanVien>::iterator item1, list<ThongTinNhanVien>::iterator item2){
    int index = 0;
    while(item1->getId()[index] != '\0' && item2->getId()[index] != '\0' && item1->getId()[index] == item2->getId()[index]){
        index++;
    }
    return (int)item1->getId()[index] - (int)item2->getId()[index];
}

void swap(list<ThongTinNhanVien>::iterator item1, list<ThongTinNhanVien>::iterator item2){
    ThongTinNhanVien temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

void QuanLy :: danhSachNV(SapXepNV type){
    int(*function)(list<ThongTinNhanVien>::iterator item1, list<ThongTinNhanVien>::iterator item2);
    for(list<ThongTinNhanVien>::iterator i = dataBaseNV.begin(); i != dataBaseNV.end(); i++)
        for(list<ThongTinNhanVien>::iterator j = dataBaseNV.begin(); j != dataBaseNV.end(); j++){
            switch (type){
                case THEO_TEN:
                    function = &sortTen;
                    if(function(j,i)> 0)
                        swap(j,i);
                    break;
                case THEO_TUOI:
                    function = &sortTuoi;
                    if(function(j,i)> 0)
                        swap(j,i);
                    break;
                case THEO_ID:
                    function = &sortID;
                    if(function(j,i)> 0)
                        swap(j,i);
                    break;
            }
        }
    displayNV();
}

void QuanLy :: quanLyNhanVien(){
    int key;
LABEL6:
    do{
        cout<<"Quan ly nhan vien"<<endl;
        cout<<"1. Them Nhan Vien"<<endl;
        cout<<"2. Xoa Nhan Vien"<<endl;
        cout<<"3. Danh Sach Nhan Vien"<<endl;
        cout<<"0. Quay lai"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key > 3 || key < 0);
    switch (key){
        case 1:
LABEL7:
            themNV();
            do{
                cout<<"1. Them nhan vien moi"<<endl;
                cout<<"0. Quay lai"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1)
                goto LABEL7;
            else 
                goto LABEL6;
        case 2:
            xoaNV();
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL6;
        case 3:
LABEL8:
            do{
                cout<<"1. Loc Theo Ten"<<endl;
                cout<<"2. Loc Theo Tuoi"<<endl;
                cout<<"3. Loc Theo ID"<<endl;
                cout<<"0. Quay lai"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key < 0 || key > 3);
            if(key == 0)
                goto LABEL6;
            else{
                SapXepNV type = (SapXepNV)key;
                danhSachNV(type);
            }
            goto LABEL8;
    }
}

float comparePrices(list<DoAn>::iterator item1, list<DoAn>::iterator item2){
    return item1->getGia() - item2->getGia();
}

void QuanLy :: danhSachMonAn(SapXepDoAn type){
    if(type == THEO_GIA){
        for(list<DoAn>::iterator i = dataBaseDoAn->begin(); i != dataBaseDoAn->end(); i++)
            for(list<DoAn>::iterator j = dataBaseDoAn->begin(); j != dataBaseDoAn->end(); j++){
                if(comparePrices(j,i) > 0){
                    DoAn temp = *j;
                    *j = *i;
                    *i = temp;
                }
            }
        displayDoAn();
        return;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"ID\tTen\tLoai\tGia"<<endl;
    for(list<DoAn>::iterator i = dataBaseDoAn->begin(); i != dataBaseDoAn->end(); i++){
        switch (type){
            case THEO_THUC_AN:
                if(i->getLoai() == THUC_AN){     
                    cout<<i->getId();
                    cout<<"\t"<<i->getTen();
                    cout<<"\tTA";
                    cout<<"\t"<<i->getGia()<<endl;     
                }
                break;
            case THEO_THUC_UONG:
                if(i->getLoai() == THUC_UONG){     
                    cout<<i->getId();
                    cout<<"\t"<<i->getTen();
                    cout<<"\tTU";
                    cout<<"\t"<<i->getGia()<<endl;     
                }
                break;
        }
    }
    cout<<"------------------------------------"<<endl; 
}

class ThongTinMon{
    private:
        string tenMon;
        string idMon;
        float giaMon;
        int soLuongMon;
    public:
        ThongTinMon(string ten, string id, float gia, int SL);

        void setTenMon(string ten);
        void setIdMon(string id);
        void setGiaMon(float gia);
        void setSoLuongMon(int SL);

        string getTenMon();
        string getIdMon();
        float getGiaMon();
        int getSoLuongMon();
};
void ThongTinMon :: setTenMon(string ten){
    this->tenMon = ten;
}
void ThongTinMon :: setIdMon(string id){
    this->idMon = id;
}
void ThongTinMon :: setGiaMon(float gia){
    this->giaMon = gia;
}
void ThongTinMon :: setSoLuongMon(int SL){
    this->soLuongMon = SL;
}
string ThongTinMon :: getTenMon(){
    return tenMon;
}
string ThongTinMon :: getIdMon(){
    return idMon;
}
float ThongTinMon :: getGiaMon(){
    return  giaMon;
}
int ThongTinMon :: getSoLuongMon(){
    return soLuongMon;
}
ThongTinMon :: ThongTinMon(string ten, string id, float gia, int SL){
    tenMon = ten;
    idMon = id;
    giaMon = gia;
    soLuongMon = SL;
}
class BanAn{
    private:
        int soBan;
        bool trangThaiBan;
        list<ThongTinMon> dataBaseMon;
    public:
        BanAn(int number, bool trangThai = false) : soBan(number), trangThaiBan(trangThai) {}
        void setTrangThai(bool trangThai);
        bool getTrangThai();
        int getSoBan();
        list<ThongTinMon> getList();
        void themMonAn(ThongTinMon thongTin);
        void suaMonAn(ThongTinMon thongTin, string id);
        void xoaMonAn(string id);
        void xoaToanBo();
};
list<ThongTinMon> BanAn :: getList(){
    return dataBaseMon;
}
void BanAn :: themMonAn(ThongTinMon thongTin){
    dataBaseMon.push_back(thongTin);
}
void BanAn :: suaMonAn(ThongTinMon thongTin, string id){
    for(list<ThongTinMon>::iterator i = dataBaseMon.begin(); i != dataBaseMon.end(); i++){
        if(compareID(i->getIdMon(),id)){
            i->setIdMon(thongTin.getIdMon());
            i->setTenMon(thongTin.getTenMon());
            i->setSoLuongMon(thongTin.getSoLuongMon());
            i->setGiaMon(thongTin.getGiaMon());
            break;
        }
    }
}
void BanAn :: xoaMonAn(string id){
    for(list<ThongTinMon>::iterator i = dataBaseMon.begin(); i != dataBaseMon.end(); i++){
        if(compareID(i->getIdMon(),id)){
            dataBaseMon.erase(i);
            break;
        }
    }
}
void BanAn :: xoaToanBo(){
    dataBaseMon.clear();
}
void BanAn :: setTrangThai(bool trangThai){
    this->trangThaiBan = trangThai;
}
int BanAn :: getSoBan(){
    return soBan;
}
bool BanAn :: getTrangThai(){
    return trangThaiBan;
}

class NhanVien{
    private:
        vector<BanAn> dataBaseBan;
        list<DoAn> dataBaseDoAn;
        int soLuongBan;
        void themMon(int num);
        void suaMon(int num);
        void xoaMon(int num);
        void danhSachMon(int num);
        void thanhToan(int num);
        void displayMon();
    public:
        NhanVien(list<DoAn> DatabaseDoAn, int soLuong);
        void displayBan();
        int getSoLuongBan();
        void quanLyBan(int num);
};
NhanVien :: NhanVien(list<DoAn> DatabaseDoAn, int soLuong){
    soLuongBan = soLuong;
    this->dataBaseDoAn = DatabaseDoAn;
    for (int i = 0; i < soLuongBan; i++){
        BanAn Ban(i+1);
        dataBaseBan.push_back(Ban);
    } 
}
void NhanVien :: displayMon(){
    cout<<"------------------------------------"<<endl;
    cout<<"ID\tTen\tLoai\tGia"<<endl;
    for(list<DoAn>::iterator i = dataBaseDoAn.begin(); i != dataBaseDoAn.end(); i++){
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<((i->getLoai() == THUC_AN) ? "TA" : "TU");
            cout<<"\t"<<i->getGia()<<endl;     
    }
    cout<<"------------------------------------"<<endl;      
}
void NhanVien :: themMon(int num){
    displayMon();
    string id;
    cout<<"Vui long nhap ID mon: ";
    cin>>id;
    for(list<DoAn>::iterator i = dataBaseDoAn.begin(); i != dataBaseDoAn.end(); i++){
        if(compareID(i->getId(), id)){
            cout<<"------------------------------------"<<endl;
            cout<<"ID\tTen\tLoai\tGia"<<endl;
            cout<<i->getId();
            cout<<"\t"<<i->getTen();
            cout<<"\t"<<((i->getLoai() == THUC_AN) ? "TA" : "TU");
            cout<<"\t"<<i->getGia()<<endl; 
            cout<<"------------------------------------"<<endl; 
            int sl;
            do{
                cout<<"Vui long nhap so luong: ";
                cin>>sl;
            }while(sl < 0);
            ThongTinMon mon(i->getTen(), i->getId(), i->getGia(), sl);
            dataBaseBan[num-1].themMonAn(mon);
            dataBaseBan[num-1].setTrangThai(true);
            cout<<"Them thanh cong"<<endl;
            return;   
        }
    }
    cout<<"Them that bai"<<endl;
}

void NhanVien :: suaMon(int num){
    danhSachMon(num);
    list<ThongTinMon> listMon = dataBaseBan[num-1].getList();
    string id, id1;
    cout<<"Vui long nhap ID mon can sua: ";
    cin>>id;
    for(list<ThongTinMon>::iterator i = listMon.begin(); i != listMon.end(); i++){
        if(compareID(i->getIdMon(), id)){
            cout<<"------------------------------------"<<endl;
            cout<<"Mon can sua: "<<endl;
            cout<<"ID\tTen\tSL\tGia"<<endl;
            cout<<i->getIdMon();
            cout<<"\t"<<i->getTenMon();
            cout<<"\t"<<i->getSoLuongMon();
            cout<<"\t"<<i->getGiaMon()<<endl;
            displayMon();
            cout<<"Vui long nhap ID mon khac: ";
            cin>>id1;
            cout<<"ID\tTen\tSL\tGia"<<endl;
            for(list<DoAn>::iterator j = dataBaseDoAn.begin(); j != dataBaseDoAn.end(); j++){
                if(compareID(j->getId(), id1)){
                    cout<<j->getId();
                    cout<<"\t"<<j->getTen();
                    cout<<"\t"<<((j->getLoai() == THUC_AN) ? "TA" : "TU");
                    cout<<"\t"<<j->getGia()<<endl; 
                    cout<<"------------------------------------"<<endl; 
                    int sl;
                    do{
                        cout<<"Vui long nhap so luong: ";
                        cin>>sl;
                    }while(sl < 0);
                    ThongTinMon tt(j->getTen(), j->getId(), j->getGia(), sl);
                    dataBaseBan[num-1].suaMonAn(tt, id);
                    cout<<"Sua thanh cong"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Sua that bai"<<endl;
}

void NhanVien :: xoaMon(int num){
danhSachMon(num);
    list<ThongTinMon> listMon = dataBaseBan[num-1].getList();
    string id;
    cout<<"Vui long nhap ID mon can xoa: ";
    cin>>id;
    for(list<ThongTinMon>::iterator i = listMon.begin(); i != listMon.end(); i++){
        if(compareID(i->getIdMon(), id)){
            cout<<"------------------------------------"<<endl;
            cout<<"Mon can xoa: "<<endl;
            cout<<"ID\tTen\tSL\tGia"<<endl;
            cout<<i->getIdMon();
            cout<<"\t"<<i->getTenMon();
            cout<<"\t"<<i->getSoLuongMon();
            cout<<"\t"<<i->getGiaMon()<<endl;
            cout<<"------------------------------------"<<endl;
            int key;
            do{
                cout<<"1. Xac nhan xoa"<<endl;
                cout<<"0. Huy"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1){
                dataBaseBan[num-1].xoaMonAn(id);
                cout<<"Xoa thanh cong"<<endl;
            }  
            return;
        }
    }
    cout<<"Xoa that bai"<<endl;
}
void NhanVien :: danhSachMon(int num){
    list<ThongTinMon> tt = dataBaseBan[num-1].getList();
    cout<<"------------------------------------"<<endl;
    cout<<"Danh sach mon cua ban "<<num<<endl;
    cout<<"ID\tTen\tSL\tGia"<<endl;
    for(auto item : tt){
        cout<<item.getIdMon();
        cout<<"\t"<<item.getTenMon();
        cout<<"\t"<<item.getSoLuongMon();
        cout<<"\t"<<item.getGiaMon()<<endl;
    }
    cout<<"------------------------------------"<<endl;  
 }
void NhanVien :: thanhToan(int num){
    int index = 1;
    float Tong = 0;
    list<ThongTinMon> tt = dataBaseBan[num-1].getList();
    cout<<"------------------------------------"<<endl;
    cout<<"Hoa don cua ban "<<num<<endl;
    cout<<"STT\tTen\tSL\tGia"<<endl;
    for(auto item : tt){
        cout<<index++;
        cout<<"\t"<<item.getTenMon();
        cout<<"\t"<<item.getSoLuongMon();
        cout<<"\t"<<item.getGiaMon()<<endl;
        Tong += (item.getGiaMon()*item.getSoLuongMon());
    }
    cout<<"------------------------------------"<<endl;
    cout<<"Tong: \t\t\t"<<Tong<<endl;
    int key;
    do{
        cout<<"1. Xac nhan thanh toan"<<endl;
        cout<<"0. Huy"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key != 0 && key != 1);
    if(key == 1){
        dataBaseBan[num-1].xoaToanBo();
        dataBaseBan[num-1].setTrangThai(false);
        cout<<"Thanh toan thanh cong"<<endl;
        return;
    }
}
int NhanVien :: getSoLuongBan(){
    return soLuongBan;
}

void NhanVien :: displayBan(){
    cout<<"----------------------------------------------"<<endl; 
    cout<<"Ban:       ";
    for (auto item : dataBaseBan){
        cout<<"\t"<<item.getSoBan();
    }
    cout<<"\r\nTrang Thai: ";
    for (auto item : dataBaseBan){
        if(item.getTrangThai() == false)
            cout<<"\tO";
        else
            cout<<"\tX";
    }
    cout<<"\r\n----------------------------------------------"<<endl; 
}

void NhanVien :: quanLyBan(int num){
    int key;
LABEL10:
    do{
        cout<<"Ban So "<<num<<endl;
        cout<<"1. Them Mon"<<endl;
        cout<<"2. Sua Mon"<<endl;
        cout<<"3. Xoa Mon"<<endl;
        cout<<"4. Danh Sach Mon"<<endl;
        cout<<"5. Thanh Toan"<<endl;
        cout<<"0. Quay lai"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key > 5 || key < 0);
    switch (key){
        case 1:
LABEL11:
            themMon(num);
            do{
                cout<<"1. Them mon moi"<<endl;
                cout<<"0. Quay lai"<<endl;
                cout<<"Vui long chon: ";
                cin>>key;
            }while(key != 0 && key != 1);
            if(key == 1)
                goto LABEL11;
            else 
                goto LABEL10;
        case 2:
            suaMon(num);
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL10;
        case 3:
            xoaMon(num);
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL10;
        case 4:
            danhSachMon(num);
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL10;
        case 5:
            thanhToan(num);
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL10;
    }
}

void Manager(QuanLy *ql){
    int key;
LABEL2:
    do{
        cout<<"Quan ly"<<endl;
        cout<<"1. Set up so luong ban"<<endl;
        cout<<"2. Set up mon an/thuc uong"<<endl;
        cout<<"3. Quan ly nhan vien"<<endl;
        cout<<"0. Quay lai"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key > 3 || key < 0);
    switch (key){
        case 1:
            ql->setSoLuongBan();
            do{
                cout<<"Nhan 0 de quay lai: ";
                cin>>key;
            }while(key != 0);
            goto LABEL2;
        case 2:
            ql->quanLyMonAn();
            goto LABEL2;  
        case 3:
            ql->quanLyNhanVien();
            goto LABEL2;    
    }
}

void Staff(NhanVien *nv){
    int soBan;
LABEL9:
    cout<<"Nhan Vien"<<endl;
    nv->displayBan();
    do{
        cout<<"Vui long chon ban (0. Quay lai): ";
        cin>>soBan;
    }while(soBan < 0 || soBan > nv->getSoLuongBan());
    if(soBan == 0)
        return;
    nv->quanLyBan(soBan);
    goto LABEL9;
}

void testList(list<DoAn> *da){
    DoAn doAn[] = {{"banh mi",THUC_AN,15000},
            {"pepsi",THUC_UONG, 8000},
            {"pho", THUC_AN, 25000},
            {"coca",THUC_UONG,10000},
            {"hu tieu", THUC_AN, 20000}};
    for (int i = 0; i < 5; i++){
        da->push_back(doAn[i]);
    } 
}

void QuanLy :: testListNV(){
    ThongTinNhanVien nv[] = {{"Tam",23,PHUC_VU,CA_CHIEU},
                             {"Binh",29,PHA_CHE,CA_SANG},
                             {"Minh",18,PHUC_VU,CA_CHIEU},
                             {"Khang",19,PHA_CHE,CA_SANG}};
    for (int i = 0; i < 4; i++){
        dataBaseNV.push_back(nv[i]);
    }                       
}

int main(int argc, char const *argv[]){
    list<DoAn> DataBaseDoAn;
    testList(&DataBaseDoAn);
    int soLuongBan = 0;
    QuanLy ql(&DataBaseDoAn, &soLuongBan);
    ql.testListNV();
    int key;
LABEL1:
    do{
        cout<<"Giao dien nguoi dung"<<endl;
        cout<<"1. Quan ly"<<endl;
        cout<<"2. Nhan vien"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long chon: ";
        cin>>key;
    }while(key > 2 || key < 0);
    switch (key){
        case 1:
            Manager(&ql);
            goto LABEL1;
        case 2:
            static NhanVien nv(DataBaseDoAn, soLuongBan);
            Staff(&nv);
            goto LABEL1;
    }
    return 0;
}
