#ifndef DANHSACHDIEMTHI_H
#define DANHSACHDIEMTHI_H
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class DanhSachSinhVien;
class DanhSachDiemThi{
    public:
        struct DiemThi{
            char Mamh[15];
            float Diem;

            DiemThi(){
                strcpy(Mamh, "");
                Diem = -1;
            };

            DiemThi(char _Mamh[], float _Diem){
                strcpy(Mamh, _Mamh);
                Diem = _Diem;
            };
        };

        struct DiemThiNode{
            DiemThi data;
            DiemThiNode *next;
        };
        typedef DiemThiNode *DTPtr;

        DanhSachDiemThi();
        ~DanhSachDiemThi();
        void xuatFileDanhSachDiemThi();
        static int demMonHocDaThi(DTPtr First);
        void insertFirst (DiemThi dt);
        void insertAfterDT (DiemThi dt, DTPtr First);
        static bool kiemTraDaThi(DTPtr First, char Mamh[15]);
        void insertDiem(DTPtr &First, DiemThi dt);
        void xuatDiemTheoLop(DanhSachSinhVien &list, char *Malop);
        DTPtr &getFirst() { 
            return First; 
        }

    private:
        DTPtr First;
};

#endif