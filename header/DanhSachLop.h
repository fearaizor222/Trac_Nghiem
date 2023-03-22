#ifndef DANHSACHLOP_H
#define DANHSACHLOP_H
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
        DanhSachSinhVien::SVPtr ptr; //Con trỏ danh sách sinh viên
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
       void insertList(int &soluong);
       void inLopRaFile();
       void themLopVaoDanhSach(Lop *List[], int &soluong);
       void xoaLopTrongDanhSach(Lop *List[], int &soluong);
       void inLopTheoNienKhoa();
       void hieuChinh();
      

};typedef danhSachLopHoc ListClasses;

#endif