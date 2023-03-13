#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "DanhSachSinhVien.h"
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
       void setSoLuong(int soluong);
       int getSoLuong();
       void insertList(Lop *List[], int &soluong);
       void inLopRaFile(Lop *List[]);
       void themLopVaoDanhSach(Lop *List[], int &soluong);
       void xoaLopTrongDanhSach(Lop *List[], int &soluong);
       void inLopTheoNienKhoa(Lop *List[]);
       DanhSachSinhVien::SVPtr ptr; //Con trỏ danh sách sinh viên

};typedef danhSachLopHoc ListClasses;