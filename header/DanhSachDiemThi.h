#pragma once
#include <string>
#include <iostream>
#include <fstream>
#ifndef DANHSACHDIEMTHI_H
#define DANHSACHDIEMTHI_H

using namespace std;

class DanhSachDiemThi{
    private:
        struct DiemThi{
            char Mamh[15];
            float Diem;
        }

        struct DiemThiNode{
            DiemThi data;
            DiemThiNode *next;
        }
        typedef DiemThiNode *DTPtr;
        
    public:
        DanhSachDiemThi();
        ~DanhSachDiemThi();
        void khoiTaoDTPtr(DTPtr *First);
        void inDiemRaFile(DTPtr First, ofstream &out);  
}





