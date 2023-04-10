#ifndef DANHSACHCAUHOI_H
#define DANHSACHCAUHOI_H

#include <string>
#include <fstream>

#define MAX_ID 5000
#define DIVISION 10

class RandomID{
    public:
        RandomID();
        ~RandomID();
        int getID();

    private:
        std::string curr_id_line;
        std::ifstream id_file;

        int rrand(int value);
        void shuffle(int *id_data);
        void randomize();
};

class DanhSachCauHoi{
    public:
        struct CauHoi
        {
            uint16_t Id;
            char ma_mon_hoc[15];
            std::string noi_dung;
            std::string dap_an_a;
            std::string dap_an_b;
            std::string dap_an_c;
            std::string dap_an_d;
            std::string dap_an;

            CauHoi();
            CauHoi(char _ma_mon_hoc[15],
                   std::string _noi_dung, std::string _dap_an_a,
                   std::string _dap_an_b, std::string _dap_an_c,
                   std::string _dap_an_d, std::string _dap_an);

            CauHoi &operator=(CauHoi &other);
        };

        struct Node
        {
            CauHoi data;
            Node *left;
            Node *right;

            Node();
            Node(CauHoi _cau_hoi);
            ~Node();
        };

        DanhSachCauHoi();
        DanhSachCauHoi(std::string path);
        ~DanhSachCauHoi();
        void insert(CauHoi _cau_hoi);
        void insert(Node *&cur, CauHoi _cau_hoi);
        void update(Node *&cur, std::ofstream &out);
        void output();
        void output(Node *cur);
        Node *&getRoot();

    private:
        Node *root;

};

static RandomID random_id;

#endif