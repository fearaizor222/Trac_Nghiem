#pragma once
#include <string.h>
#include <fstream>
#include <string>
#define MAX_MON 300

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
        DanhSachMonHoc(std::string path);  //  Nhận 1 đường dẫn đến file .csv, lấy MAMH và TENMH
        void insert(MonHoc *mon_hoc);  //  gắn dữ liệu môn dựa theo MAMH
        void output();  //  debugging only use, will remove after done

    private:
        short length;
        MonHoc *data[MAX_MON];

        void move(int index);  //  di chuyển dữ liệu qua bên phải
};