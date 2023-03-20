#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "DanhSachDiemThi.h"
using namespace std;

class DanhSachSinhVien{
    public:

        struct SinhVien{
            char MASV[15];
            char HO[21];
            char TEN[16];
            bool Phai; // Nam = 0, Nu = 1
            char password[8];
            DanhSachDiemThi::DTPtr ptr; //Con trỏ quản lý danh sách điểm thi
       
        struct Date{
                int ngay, thang, nam;
            };
            SinhVien();
           SinhVien(char MASV[15], char HO[21], char TEN[16], bool Phai, char password[8]);
        };

        struct SinhVienNode{
            SinhVien data;
            SinhVienNode *next;
        };
        typedef SinhVienNode *SVPtr;
       
        DanhSachSinhVien();
        ~DanhSachSinhVien();
        void inSinhVienRaFile(SVPtr First);
        void insertFirst(SinhVien sv);
        void insertAfterSV(SVPtr First , SinhVien sv);
        SVPtr &getFirst() { 
            return First; 
        }
    private:
        SVPtr First;

};