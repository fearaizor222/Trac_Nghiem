#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

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
        void xuatDanhSachDiemThi();
        void insertFirst (DiemThi dt);
        void insertAfterDT (DiemThi dt, DTPtr First);
        bool kiemTraDaThi(char Mamh[15]);
        void insertDiem(DTPtr &First, DiemThi dt);
        DTPtr &getFirst() { 
            return First; 
        }
    private:
        DTPtr First;
        // void khoiTaoDTPtr(DTPtr *First);
};