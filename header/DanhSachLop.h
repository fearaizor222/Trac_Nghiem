#ifndef DANHSACHLOP_H
#define DANHSACHLOP_H
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
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
        friend ostream &operator<<(std::ostream &out, Lop lop_hoc);
};
class danhSachLopHoc{
    private:
        int soluong; 
        Lop *List[MAX_DSL];
        void move(int index, int offset);
    public:
       danhSachLopHoc();
       ~danhSachLopHoc();
       danhSachLopHoc(string path);
       void setSoLuong(int soluong);
       int getSoLuong();
       void insertList(int &soluong);
       void themLopVaoDanhSach(Lop *List[], int &soluong);
       void xoaLopTrongDanhSach(Lop *List[], int &soluong);
       void inLopTheoNienKhoa();
       void hieuChinh();
       void insert(Lop *lop_hoc,bool write_to_file);
       int searchClass(string malop);
       void update(Lop *lop_hoc);
       Lop &operator[](int index); 
      

};typedef danhSachLopHoc ListClasses;

#endif