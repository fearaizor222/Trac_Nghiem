#pragma once
#include <iostream>
#include <fstream>

#include "../header/DanhSachDiemThi.h"
#include "../header/DanhSachDiemThi.h"
#include "DanhSachDiemThi.h"
using namespace std;

class DanhSachSinhVien{
    public:
        struct SinhVien{
            char MASV[15];
            char HO[21];
            char TEN[16];
            bool Phai; // Nam = 0, Nu = 1
            char password[21];

            DanhSachDiemThi::DTPtr DanhSachDiemThi; //Con trỏ quản lý danh sách điểm thi
            DanhSachDiemThi::DTPtr ptr; //Con trỏ quản lý danh sách điểm thi

        };

        struct SinhVienNode{
            SinhVien data;
            SinhVienNode *next;
        };
        typedef SinhVienNode *SVPtr;

        DanhSachSinhVien();
        ~DanhSachSinhVien();
        void insertFirst(SVPtr &First, SinhVien sv);
        void insertLast(SVPtr &First, SinhVien sv);
        void inSinhVienRaFile(SVPtr First);
    private:
        int soluong;
        SVPtr First = NULL;
};

