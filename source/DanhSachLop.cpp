#include "../header/DanhSachLop.h"
Lop::Lop(){
    maLop = tenLop = "N/A";
    nienKhoa = 0;
}
void Lop::setMaLop(string maLop){
    this->maLop = maLop;
}
string Lop::getMaLop(){
    return maLop;
}
void Lop::setTenLop(string tenLop){
    this->tenLop = tenLop;
}
string Lop::getTenLop(){
    return tenLop;
}
void Lop::setNienKhoa(int nienKhoa){
    this->nienKhoa = nienKhoa;
}
int Lop::getNienKhoa(){
    return nienKhoa;
}
