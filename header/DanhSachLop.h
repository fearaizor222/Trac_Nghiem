#pragma once
#include <string>
#include <iostream>
#define MAX_DSL 500
using namespace std;

class Lop{
    private:
        string malop;
        string tenlop;
        int nienkhoa;
    public:
        Lop(string malop, string tenlop, int nienkhoa );
        void setMaLop(string malop);
        string getMaLop();
        void setTenLop(string tenlop);
        string getTenLop();
        void setNienKhoa(int nienkhoa);
        int getNienKhoa();
        Lop();
};


class danhSachLopHoc{
    private:
        int soluong; 
        Lop *List[MAX_DSL];
    public:
       danhSachLopHoc();
       ~danhSachLopHoc();
       void init();
       void setSoLuong(int soluong);
       int getSoLuong();
       void insertList();


};typedef danhSachLopHoc ListClasses;