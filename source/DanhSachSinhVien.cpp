
#include "../header/DanhSachSinhVien.h"
DanhSachSinhVien::DanhSachSinhVien(){
    soluong = 0;
    ofstream out("../data/DANHSACHSINHVIEN.csv", ios::out); 
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma Sinh Vien"<<","<<"Ho"<<","<<"Ten"<<","<<"Phai"<<";"<<"Password"<<endl;
    out.close();
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
void DanhSachSinhVien::insertFirst(SVPtr &First, SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->data = sv;
    p->next = First;
    First = p;
}
void DanhSachSinhVien::insertLast(SVPtr &First, SinhVien sv){
      SVPtr p = new SinhVienNode;
    p->data = sv;
    p->next = NULL;
    if(First == NULL){
        First = p;
    }else{
        SVPtr q = First;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}