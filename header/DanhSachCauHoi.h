#pragma once
#include <cstdint>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <iostream>
#define RANDOM 150

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
            CauHoi(uint16_t _Id, char _ma_mon_hoc[15],
                   std::string _noi_dung, std::string _dap_an_a,
                   std::string _dap_an_b, std::string _dap_an_c,
                   std::string _dap_an_d, std::string _dap_an);

            CauHoi &operator=(CauHoi &other){
                this->Id = other.Id;
                strcpy(this->ma_mon_hoc, other.ma_mon_hoc);
                this->noi_dung = other.noi_dung;
                this->dap_an_a = other.dap_an_a;
                this->dap_an_b = other.dap_an_b;
                this->dap_an_c = other.dap_an_c;
                this->dap_an = other.dap_an;
                return *this;
            }
        };

        struct Node
        {
            CauHoi data;
            Node *left;
            Node *right;

            Node();
            Node(CauHoi _cau_hoi);
        };

        DanhSachCauHoi();
        DanhSachCauHoi(std::string path);
        void insert(CauHoi _cau_hoi);
        void insert(Node *&cur, CauHoi _cau_hoi);
        void output();
        void output(Node *cur);
        Node *&getRoot();

    private:
        Node *root;
        uint16_t id_data[RANDOM];
        int length;

        int rrand(int value);
        void random();
};