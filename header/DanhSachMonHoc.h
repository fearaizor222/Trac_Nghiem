#ifndef DANHSACHMONHOC_H
#define DANHSACHMONHOC_H
#include <string>

#define MAX_MON 300

class DanhSachMonHoc{
    public:
        struct MonHoc{
            char ma_mon_hoc[16];
            std::string ten_mon_hoc;

            MonHoc();
            MonHoc(char ma_mon_hoc[15], std::string ten_mon_hoc);
            friend std::ostream &operator<<(std::ostream &out, MonHoc mon_hoc);
        };

        DanhSachMonHoc();
        DanhSachMonHoc(std::string path);
        void insert(MonHoc mon_hoc, bool write_to_file = 1);  
        int search(char ma_mon_hoc[]);  
        void remove(char ma_mon_hoc[]);
        void update(MonHoc mon_hoc);
        void output();

        MonHoc &operator[](int index);

    private:
        short length;
        MonHoc data[MAX_MON];

        void move(int index, int offset);  // Di chuyển dữ liệu qua bên phải hoặc bên trái
};

#endif