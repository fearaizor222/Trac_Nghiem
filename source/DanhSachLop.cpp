#include "../header/DanhSachLop.h"
Lop::Lop(){
    malop = tenlop = "N/A";
    nienkhoa = 0;
}
void Lop::setMaLop(string malop){
    this->malop = malop;
}
string Lop::getMaLop(){
    return malop;
}
void Lop::setTenLop(string tenlop){
    this->tenlop = tenlop;
}
string Lop::getTenLop(){
    return tenlop;
}
void Lop::setNienKhoa(int nienkhoa){
    this->nienkhoa = nienkhoa;
}
Lop::setMaLop(string maLop){
    this->maLop = maLop;
}
Lop::getMaLop(){
    return maLop;
}
Lop::setTenLop(string tenLop){
    this->tenLop = tenLop;
}
Lop::getTenLop(){
    return tenLop;
}
Lop::setNienKhoa(int nienKhoa){
    this->nienKhoa = nienKhoa;
}
Lop::getNienKhoa(){
    return nienKhoa;
}


