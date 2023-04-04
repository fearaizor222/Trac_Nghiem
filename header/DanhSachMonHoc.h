#ifndef DANHSACHMONHOC_H
#define DANHSACHMONHOC_H
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
            friend std::ostream &operator<<(std::ostream &out, MonHoc mon_hoc);
        };

        DanhSachMonHoc();
        DanhSachMonHoc(std::string path);  //  Nhận 1 đường dẫn đến file .txt, lấy MAMH và TENMH
        void insert(MonHoc mon_hoc, bool write_to_file = 1);  //  Gắn dữ liệu môn dựa theo MAMH
        int searchByID(char ma_mon_hoc[]);  // Tìm kiếm phần tử theo mã môn
        void deleteByID(char ma_mon_hoc[]);  // Xóa phần tử theo mã môn
        void update(MonHoc mon_hoc);  // Cập nhật dữ liệu vào file
        void output();  // debugging only use, will remove after done

        MonHoc &operator[](int index);

    private:
        short length;
        MonHoc data[MAX_MON];

        void move(int index, int offset);  // Di chuyển dữ liệu qua bên phải hoặc bên trái
};

#endif