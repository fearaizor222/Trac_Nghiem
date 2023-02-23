#include "../header/DanhSachLop.h"
Lop::Lop(){
    maLop = tenLop = "N/A";
    nienKhoa = 0;
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
