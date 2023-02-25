#pragma once
#include <iostream>
#include <fstream>
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
        void khoiTaoDTPtr(DTPtr *First);
        void inDiemRaFile(DTPtr First, ofstream &out); 
    private:
        DTPtr First=NULL;
};