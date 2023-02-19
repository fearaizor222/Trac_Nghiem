#pragma once
#include <string.h>
#include <fstream>
#include <string>
#define MAXARR 300

class DanhSachMonHoc{
    public:
        struct MonHoc{
            char ma_mon_hoc[15];
            std::string ten_mon_hoc;

            MonHoc();
            MonHoc(char ma_mon_hoc[15], std::string ten_mon_hoc);
        };

        DanhSachMonHoc();
        ~DanhSachMonHoc();
        DanhSachMonHoc(std::string path);
        void insert(MonHoc *mon_hoc);
        void output();

    private:
        short length;
        MonHoc *data[MAXARR];

        void move(int index);
};