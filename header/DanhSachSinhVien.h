#pragma once
// #include "DanhSachDiemThi.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class DanhSachDiemThi;
class DanhSachSinhVien{
    public:

        struct SinhVien{
            char MASV[15];
            char HO[21];
            char TEN[16];
            bool Phai; // Nam = 0, Nu = 1
            char password[8];
            DanhSachDiemThi::DTPtr ptr ; //Con trỏ quản lý danh sách điểm thi
       
        struct Date{
                int ngay, thang, nam;
            };
            SinhVien();
           SinhVien(char MASV[15], char HO[21], char TEN[16], bool Phai, char password[8]);
        };

        struct SinhVienNode{
            SinhVien sv_data;
            SinhVienNode *next;
        };
        typedef SinhVienNode *SVPtr;
       
        DanhSachSinhVien();
        ~DanhSachSinhVien();
        void inSinhVienRaFile(SVPtr FirstSV);
        void insertFirst(SinhVien sv);
        void insertAfterSV(SVPtr FirstSV , SinhVien sv);
        SVPtr &getFirst() { 
            return FirstSV; 
        }
    private:
        SVPtr FirstSV;
};