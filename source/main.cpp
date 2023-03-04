#include <iostream> 
#include "../header/DanhSachDiemThi.h"
#include <fstream>
using namespace std;

int main(){
    DanhSachDiemThi dsdt;
    DanhSachDiemThi::DiemThi dt;
    strcpy(dt.Mamh, "C++");
    dt.Diem = 10;
    DanhSachDiemThi::DTPtr First = dsdt.getFirst();
    dsdt.insertDiem(First, dt);
    dsdt.xuatDanhSachDiemThi(First);
    return 0;
}
