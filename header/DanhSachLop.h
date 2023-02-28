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
        void setMaLop(string maLop);
        string getMaLop();
        void setTenLop(string tenlop);
        string getTenLop();
        void setNienKhoa(int nienKhoa);
        int getNienKhoa();
        Lop();
};


class danhSachLopHoc{
    private:
    Lop *PTR[MAX_DSL];
};