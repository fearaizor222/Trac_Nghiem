#include "../header/DanhSachSinhVien.h"

DanhSachSinhVien::SinhVien::SinhVien(){
     strcpy_s(MASV, 15, "");
     strcpy_s(HO, 21, "");
     strcpy_s(TEN, 16, "");     
     strcpy_s(password, 8, "");
     Phai = -1;

}
DanhSachSinhVien::SinhVien::SinhVien(char MASV[15], char HO[21], char TEN[16], bool Phai, char password[8]){
    strncpy(this->MASV, MASV, 15);
    strncpy(this->HO, HO, 21);
    strncpy(this->TEN, TEN, 16);
    strncpy(this->password, password, 8);
    this->Phai = Phai;
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