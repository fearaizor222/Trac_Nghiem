#ifndef DANHSACHSINHVIEN_H  
#define DANHSACHSINHVIEN_H
#include "DanhSachDiemThi.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// class DanhSachDiemThi;
class DanhSachSinhVien{
    public:

        struct SinhVien{
            string MASV;
            string HO;
            string TEN;
            bool Phai; // Nam = 0, Nu = 1
            string password;
            DanhSachDiemThi::DTPtr ptr ; //Con trỏ quản lý danh sách điểm thi
       
        struct Date{
                int ngay, thang, nam;
                Date();
                Date(int ngay, int thang, int nam);
            };
           SinhVien();
           SinhVien(string MASV, string HO, string TEN, bool Phai, string password);
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

#endif