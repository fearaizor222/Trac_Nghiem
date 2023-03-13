#include "../header/DanhSachCauHoi.h"


DanhSachCauHoi::CauHoi::CauHoi(){
    Id = -1;
    strncpy(ma_mon_hoc, "", 15);
    noi_dung = "";
    dap_an_a = "";
    dap_an_b = "";
    dap_an_c = "";
    dap_an_d = "";
    dap_an = "";
}

DanhSachCauHoi::CauHoi::CauHoi(uint16_t _Id, char _ma_mon_hoc[15],
                               std::string _noi_dung, std::string _dap_an_a,
                               std::string _dap_an_b, std::string _dap_an_c,
                               std::string _dap_an_d, std::string _dap_an){
    Id = _Id;
    strncpy(ma_mon_hoc, _ma_mon_hoc, 15);
    noi_dung = _noi_dung;
    dap_an_a = _dap_an_a;
    dap_an_b = _dap_an_b;
    dap_an_c = _dap_an_c;
    dap_an_d = _dap_an_d;
    dap_an = _dap_an;
}

DanhSachCauHoi::Node::Node() : data(){
    left = nullptr;
    right = nullptr;
}

DanhSachCauHoi::Node::Node(CauHoi _cau_hoi){
    data = _cau_hoi;
    left = nullptr;
    right = nullptr;
}

DanhSachCauHoi::DanhSachCauHoi(){
    root = nullptr;
    random();
}

DanhSachCauHoi::Node *&DanhSachCauHoi::getRoot(){
    return root;
}

DanhSachCauHoi::DanhSachCauHoi(std::string path) : DanhSachCauHoi(){
    std::ifstream input(path);
    
    
}

void DanhSachCauHoi::insert(Node *&cur, CauHoi _cau_hoi){ 
    if(cur == nullptr) cur = new Node(_cau_hoi);
    else{
        if(cur->data.Id > _cau_hoi.Id) insert(cur->left, _cau_hoi);
        else insert(cur->right, _cau_hoi);
    }
}

void DanhSachCauHoi::output(Node *cur){
    if(cur != nullptr){
        std::cout<<cur->data.Id<<" ";
        output(cur->left);
        output(cur->right);
    }
}

int DanhSachCauHoi::rrand(int value)
{
    return (int)((double)value * (rand() / (RAND_MAX + 1.0)));
}

void DanhSachCauHoi::random()
{
    for (int i = 0; i < RANDOM; i++)
    {
        id_data[i] = i + 1;
    }
    for (int i = RANDOM; i > 1; i--)
    {
        int num = rrand(i);
        int temp = id_data[i - 1];

        id_data[i - 1] = id_data[num];
        id_data[num] = temp;
    }
}