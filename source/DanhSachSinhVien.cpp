#include "../header/DanhSachSinhVien.h"

DanhSachSinhVien::SinhVien::SinhVien(){
     MASV = HO = TEN = password = "";
     Phai = -1;

}
DanhSachSinhVien::SinhVien::SinhVien(string MASV, string HO, string TEN, bool Phai, string password){
    this->MASV = MASV;
    this->HO = HO;
    this->TEN = TEN;
    this->password = password;
    this->Phai = Phai;
}
DanhSachSinhVien::SinhVien::Date::Date(){
    ngay = thang = nam = -1;
}
DanhSachSinhVien::SinhVien::Date::Date(int ngay, int thang, int nam){
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}
DanhSachSinhVien::DanhSachSinhVien(){
    FirstSV = nullptr;
}
DanhSachSinhVien::~DanhSachSinhVien(){ 
    SVPtr p = FirstSV;
    while(p != NULL){
        SVPtr q = p;
        p = p->next;
        delete q;
    }
}
void DanhSachSinhVien::inSinhVienRaFile(SVPtr FirstSV){
    ofstream out("../data/DANHSACHSINHVIEN.csv", ios::out); 
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma Sinh Vien"<<","<<"Ho"<<","<<"Ten"<<","<<"Phai"<<";"<<"Password"<<endl;
    SVPtr p = FirstSV;
    while( p!=NULL ){
        out<<p->sv_data.MASV<<p->sv_data.HO<<p->sv_data.TEN<<p->sv_data.Phai<<endl;
        p = p->next;
    }
    out.close();
}
void DanhSachSinhVien::insertFirst(SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->sv_data = sv;
    p->next = FirstSV;
    FirstSV = p;
}
void DanhSachSinhVien::insertAfterSV(SVPtr FirstSV, SinhVien sv){
     SVPtr p;
    if (FirstSV == NULL){
        cout << "Khong the them phan tu vao danh sach" << endl;
    } else {
        p = new SinhVienNode;
        p->sv_data = sv;
        p->next = FirstSV->next;
        FirstSV->next = p;
    }
}