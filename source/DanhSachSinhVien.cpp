#include "../header/DanhSachSinhVien.h"

DanhSachSinhVien::SinhVien::SinhVien(){
     MASV = HO = TEN = Phai = password = "";

}
DanhSachSinhVien::SinhVien::SinhVien(string MASV, string HO, string TEN, string Phai, string password){
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

void DanhSachSinhVien::insertFirst(SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->sv_data = sv;
    p->next = FirstSV;
    FirstSV = p;
}

void DanhSachSinhVien::insertAfter(SVPtr p, SinhVien sv){
    if(p==NULL){
        cout<<"Khong the them vao vi tri nay";
        return;
    }
    SVPtr q = new SinhVienNode;
    q->sv_data = sv;
    q->next = p->next;
    p->next = q;
}

void DanhSachSinhVien::insertSV(SinhVien sv){
    if (FirstSV == NULL){
        insertFirst(sv);
        return;
    }
    else{
        SVPtr p = new SinhVienNode;
        p=FirstSV;
        while(p->next!=NULL){
            p=p->next;
        }
        insertAfter(p, sv);
    }
}
DanhSachSinhVien::DanhSachSinhVien(std::string path):DanhSachSinhVien(){
    ifstream input(path);
      if(!input.is_open()){
        std::string error = "Không thể mở file: " + path;
        throw error;
    }
    string line;
    while(getline(input,line)){
        stringstream _line(line);
        string Ma_SV, Ho, Ten, PHAI, PASSWORD;
        getline(_line,Ma_SV,'|');
        getline(_line,Ho, '|');
        getline(_line,Ten,'|');
        getline(_line,PHAI,'|');
        getline(_line,PASSWORD,'|');
        insertSV(SinhVien(Ma_SV, Ho, Ten, PHAI, PASSWORD));
    }
}
