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
        };

        struct DiemThiNode{
            DiemThi data;
            DiemThiNode *next;
        };
        typedef DiemThiNode *DTPtr;

        DanhSachDiemThi();
        ~DanhSachDiemThi();
        void xuatDanhSachDiemThi(DTPtr First);
        void insertFirst (DTPtr &First, DiemThi dt);
        void insertLast (DTPtr &First, DiemThi dt); 
        bool kiemTraDaThi(DTPtr First, char Mamh[15]);
        void insertDiem(DTPtr &First, DiemThi dt);
        DTPtr getFirst() { 
            return First; 
        }
    private:
        DTPtr First=NULL;
        void khoiTaoDTPtr(DTPtr *First);
};