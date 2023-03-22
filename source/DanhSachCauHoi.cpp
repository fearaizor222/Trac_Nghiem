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
    length = 0;
    random();
}

DanhSachCauHoi::Node *&DanhSachCauHoi::getRoot(){
    return root;
}

DanhSachCauHoi::DanhSachCauHoi(std::string path) : DanhSachCauHoi(){
    std::ifstream input(path);
    std::string line;
    std::string ma_mon = path.substr(0, path.find("."));
    while(getline(input, line)){
        std::stringstream _line(line);
        std::string noi_dung, cau_a, cau_b, cau_c, cau_d, dap_an;
        getline(_line, noi_dung, '|');
        getline(_line, cau_a, '|');
        getline(_line, cau_b, '|');
        getline(_line, cau_c, '|');
        getline(_line, cau_d, '|');
        getline(_line, dap_an);

        insert(root, {id_data[length++], (char*)ma_mon.c_str(), noi_dung, cau_a, cau_b, cau_c, cau_d, dap_an});
    }
}

void DanhSachCauHoi::insert(CauHoi _cau_hoi){ 
    if(root == nullptr) root = new Node(_cau_hoi);
    else{
        if(root->data.Id > _cau_hoi.Id) insert(root->left, _cau_hoi);
        else insert(root->right, _cau_hoi);
    }
}

void DanhSachCauHoi::insert(Node *&cur, CauHoi _cau_hoi){ 
    if(cur == nullptr) cur = new Node(_cau_hoi);
    else{
        if(cur->data.Id > _cau_hoi.Id) insert(cur->left, _cau_hoi);
        else insert(cur->right, _cau_hoi);
    }
}

void DanhSachCauHoi::output(){
    if(root != nullptr){
        std::cout<<root->data.Id<<std::endl;
        output(root->left);
        output(root->right);
    }
}

void DanhSachCauHoi::output(Node *cur){
    if(cur != nullptr){
        std::cout<<cur->data.Id<<std::endl;
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
    srand(time(0));
    for (int i = 0; i < RANDOM; i++)
    {
        id_data[i] = i + 1;
    }
    for (int i = RANDOM; i > 1; i--)
    {
        int num = rand()%RANDOM;
        int temp = id_data[i - 1];

        id_data[i - 1] = id_data[num];
        id_data[num] = temp;
    }
}