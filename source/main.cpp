#include "..\header\DanhSachDiemThi.h"
using namespace std;

int main(){
    DanhSachDiemThi dsdt;
    DanhSachDiemThi::DTPtr First = dsdt.getFirst();
    DanhSachDiemThi::DiemThi dt;
    strcpy(dt.Mamh, "C++");
    dt.Diem = 10;
    dsdt.insertFirst(First, dt);
    dsdt.xuatDanhSachDiemThi(First);
    return 0;
}