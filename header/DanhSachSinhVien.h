#ifndef DANHSACHSINHVIEN_H  
#define DANHSACHSINHVIEN_H
#include "DanhSachDiemThi.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

// class DanhSachDiemThi;
class DanhSachSinhVien{
    public:
        struct SinhVien
        {
            string MASV;
            string HO;
            string TEN;
            string Phai; // Nam = 0, Nu = 1
            string password;
            DanhSachDiemThi *diem; // Con trỏ quản lý danh sách điểm thi

            SinhVien();
            SinhVien(string MASV, string HO, string TEN, string Phai, string password);
            SinhVien(const SinhVien &sv);
            SinhVien &operator=(const SinhVien &sv);
            ~SinhVien();
        };

        struct SinhVienNode
        {
            SinhVien sv_data;
            SinhVienNode *next;
        };
        typedef SinhVienNode *SVPtr;

        DanhSachSinhVien();
        ~DanhSachSinhVien();
        DanhSachSinhVien(string path);
        DanhSachSinhVien &operator=(const DanhSachSinhVien &dssv);
        DanhSachSinhVien(const DanhSachSinhVien &dssv);
        // void inSinhVienRaFile(SVPtr FirstSV);
        void insertFirst(SinhVien sv);
        // void insertSV(SinhVien sv);
        void insertAfter(SVPtr FirstSV, SinhVien sv);
        void insertLast(SinhVien sv);
        void deleteSV(string MASV);
        void setPath(string path);
        string getPath();
        bool isEmpty();
        SVPtr &getFirst();

        void update();
        // SinhVien &operator[](int index);

        SinhVien &operator[](string _MASV);
    private:
        int length;
        SVPtr FirstSV;
        std::string path;
        // void move(int index, int offset);
};

typedef DanhSachSinhVien::SinhVien SinhVien;
typedef DanhSachSinhVien::SVPtr SVPtr;

#endif