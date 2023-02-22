#pragma once
#include <iostream>
#define MAX_DSL 500
using namespace std;

class Lop{
    private:
    string maLop;
    string tenLop;
    int nienKhoa;
    public:
    Lop(string maLop, string tenLop, int nienKhoa );

    string getMaLop();
    void setMaLop(string maLop);
    string getTenLop();
    void setTenLop(string tenlop);
    int getNienKhoa();
    void setNienKhoa(int nienKhoa);
};


class danhSachLopHoc{
    private:
    Lop *PTR[MAX_DSL];
};