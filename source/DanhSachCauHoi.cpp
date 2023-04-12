#include "../header/DanhSachCauHoi.h"
#include <cstdint>
#include <sstream>
#include <cstring>
#include <iostream>

RandomID::RandomID(){
    randomize();
    id_file.open("../data/ID.txt");
    if(id_file.is_open()){
        std::getline(id_file, curr_id_line);
    }
}

RandomID::~RandomID(){
    id_file.close();
}

int RandomID::rrand(int value){
    return (int)((double)value * (rand() / (RAND_MAX + 1.0)));
}

int RandomID::getID(){
    if(curr_id_line.empty()){
        std::getline(id_file, curr_id_line);
    }

    if(curr_id_line.empty()){
        return -1;
    }

    std::stringstream ss(curr_id_line);
    std::string number;
    getline(ss, number, '|');
    int num = stoi(number);
    getline(ss, curr_id_line);
    return num;
}

void RandomID::shuffle(int *id_data){
    for (int i = 0; i < MAX_ID; i++){
        id_data[i] = i + 1;
    }

    for (int i = MAX_ID; i > 1; i--){
        int num = rrand(i);
        int temp = id_data[i - 1];

        id_data[i - 1] = id_data[num];
        id_data[num] = temp;
    }
}

void RandomID::randomize(){
    srand(time(NULL));
    std::ofstream out("../data/ID.txt");
    int array[MAX_ID];
    std::string attach;
    shuffle(array);

    for (int i = 0; i < MAX_ID / DIVISION; i++){
        for(int j = 0; j < DIVISION; j++){            
            attach = (j == DIVISION - 1)? "|\n" : "|";
            out << array[i * DIVISION + j] << attach;
        }
    }

    out.close();
}

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

DanhSachCauHoi::CauHoi::CauHoi(char _ma_mon_hoc[15],
                               std::string _noi_dung, std::string _dap_an_a,
                               std::string _dap_an_b, std::string _dap_an_c,
                               std::string _dap_an_d, std::string _dap_an){
    Id = random_id.getID();
    strncpy(ma_mon_hoc, _ma_mon_hoc, 15);
    noi_dung = _noi_dung;
    dap_an_a = _dap_an_a;
    dap_an_b = _dap_an_b;
    dap_an_c = _dap_an_c;
    dap_an_d = _dap_an_d;
    dap_an = _dap_an;
}

DanhSachCauHoi::CauHoi &DanhSachCauHoi::CauHoi::operator=(CauHoi &other){
    this->Id = other.Id;
    strcpy(this->ma_mon_hoc, other.ma_mon_hoc);
    this->noi_dung = other.noi_dung;
    this->dap_an_a = other.dap_an_a;
    this->dap_an_b = other.dap_an_b;
    this->dap_an_c = other.dap_an_c;
    this->dap_an_d = other.dap_an_d;
    this->dap_an = other.dap_an;
    return *this;
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
 
DanhSachCauHoi::Node::~Node(){
    delete left;
    delete right;
}

DanhSachCauHoi::DanhSachCauHoi(){
    root = nullptr;
}

DanhSachCauHoi::~DanhSachCauHoi(){
    std::ofstream out("../data/DANHSACHCAUHOI.txt");
    update(root, out);
    out.close();

    delete root;
}

DanhSachCauHoi::Node *&DanhSachCauHoi::getRoot(){
    return root;
}

DanhSachCauHoi::DanhSachCauHoi(std::string path) : DanhSachCauHoi(){
    std::ifstream input(path);
    std::string line;
    while(getline(input, line)){
        std::stringstream _line(line);
        std::string ma_mon, noi_dung, cau_a, cau_b, cau_c, cau_d, dap_an;
        getline(_line, ma_mon, '|');
        getline(_line, noi_dung, '|');
        getline(_line, cau_a, '|');
        getline(_line, cau_b, '|');
        getline(_line, cau_c, '|');
        getline(_line, cau_d, '|');
        getline(_line, dap_an);
        
        insert({
            (char*)ma_mon.c_str(),
            noi_dung,
            cau_a,
            cau_b,
            cau_c,
            cau_d,
            dap_an
        });
    }
}

void DanhSachCauHoi::insert(CauHoi _cau_hoi){
    insert(root, _cau_hoi);    
}

void DanhSachCauHoi::insert(Node *&cur, CauHoi _cau_hoi){ 
    if(cur == nullptr) cur = new Node(_cau_hoi);
    else{
        if(cur->data.Id > _cau_hoi.Id) insert(cur->left, _cau_hoi);
        else insert(cur->right, _cau_hoi);
    }
}

void DanhSachCauHoi::remove(int id){
    remove(root, id); 
}

void DanhSachCauHoi::remove(Node *&cur, int id){
    if(cur == nullptr) return;
    else if(id < cur->data.Id) remove(cur->left, id);
    else if(id > cur->data.Id) remove(cur->right, id);
    else{
        temporary = cur;
        if(temporary->right == nullptr) cur = temporary->left;
        else if(temporary->left == nullptr) cur = temporary->right;
        else removeWithTwoChildren(cur->right);
        delete temporary;
    }
}

void DanhSachCauHoi::removeWithTwoChildren(Node *&cur){
    if(cur->left != nullptr)
        removeWithTwoChildren(cur->left);
    else{
        temporary->data = cur->data;
        temporary = cur;
        cur = temporary->right;
    }
}

void DanhSachCauHoi::update(Node *&cur, std::ofstream &out){
    if(cur != nullptr){
        update(cur->left, out);
        out<<cur->data.ma_mon_hoc<<"|"<<cur->data.noi_dung<<"|"<<cur->data.dap_an_a<<"|"<<cur->data.dap_an_b<<"|"<<cur->data.dap_an_c<<"|"<<cur->data.dap_an_d<<"|"<<cur->data.dap_an<<std::endl;
        update(cur->right, out);
    }
}

void DanhSachCauHoi::output(){
    output(root);
}

void DanhSachCauHoi::output(Node *cur){
    if(cur != nullptr){
        std::cout<<cur->data.Id<<" ";
        output(cur->left);
        output(cur->right);
    }
}

