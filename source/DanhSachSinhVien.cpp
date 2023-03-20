
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
    First = nullptr;
}
DanhSachSinhVien::~DanhSachSinhVien(){ 
    SVPtr p = First;
    while(p != NULL){
        SVPtr q = p;
        p = p->next;
        delete q;
    }
}
void DanhSachSinhVien::inSinhVienRaFile(SVPtr First){
    ofstream out("../data/DANHSACHSINHVIEN.csv", ios::out); 
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma Sinh Vien"<<","<<"Ho"<<","<<"Ten"<<","<<"Phai"<<";"<<"Password"<<endl;
    SVPtr p = First;
    while( p!=NULL ){
        out<<p->data.MASV<<p->data.HO<<p->data.TEN<<p->data.Phai<<endl;
        p = p->next;
    }
    out.close();
}
void DanhSachSinhVien::insertFirst(SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->data = sv;
    p->next = First;
    First = p;
}
void DanhSachSinhVien::insertAfterSV(SVPtr First, SinhVien sv){
     SVPtr p;
    if (First == NULL){
        cout << "Khong the them phan tu vao danh sach" << endl;
    } else {
        p = new SinhVienNode;
        p->data = sv;
        p->next = First->next;
        First->next = p;
    }
}