#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class DanhSachSinhVien{
    public:
        struct SinhVien{
            char MASV[15];
            char HO[21];
            char TEN[16];
            bool Phai; // Nam = 0, Nu = 1
            char password[21];
            DTPtr DanhSachDiemThi; //Con trỏ quản lý danh sách điểm thi
        };

        struct SinhVienNode{
            SinhVien data;
            SinhVienNode *next;
        };
        typedef SinhVienNode *SVPtr;

        DanhSachSinhVien();
        ~DanhSachSinhVien();
        void inSinhVienRaFile(SVPtr First, ofstream &out);
};