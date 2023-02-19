#include "../header/DanhSachMonHoc.h"
#include <iostream>

DanhSachMonHoc::MonHoc::MonHoc(){
    strcpy_s(ma_mon_hoc, 15, "");
    ten_mon_hoc = "";
}

DanhSachMonHoc::MonHoc::MonHoc(char ma_mon_hoc[15], std::string ten_mon_hoc){
    strcpy_s(this->ma_mon_hoc, 15, ma_mon_hoc);
    this->ten_mon_hoc = ten_mon_hoc;
}

DanhSachMonHoc::DanhSachMonHoc(){
    length = 0;
}

DanhSachMonHoc::~DanhSachMonHoc(){
    for(int i = 0; i<length; i++){
        delete data[i];
    }
}

DanhSachMonHoc::DanhSachMonHoc(std::string path) : DanhSachMonHoc(){
    std::string rawline = "";
    std::ifstream input(path);
    while(std::getline(input, rawline)){
        std::string ma_mon = rawline.substr(0, rawline.find(","));
        std::string ten_mon = rawline.substr(rawline.find(",") + 1, rawline.size() - 1);

        this->insert(new MonHoc((char*)ma_mon.c_str(), ten_mon));
    }
}

void DanhSachMonHoc::move(int index){
    MonHoc *ptr1 = data[index];
    for(int i = index + 1; i<=length; i++){
        MonHoc *ptr2 = data[i];
        data[i] = ptr1;
        ptr1 = ptr2;
    }
}

void DanhSachMonHoc::insert(MonHoc *mon_hoc){
    // if(length == 0){
    //     data[length] = mon_hoc;   may have unforeseen consequences, so i didnt remove
    //     length++;
    //     return;
    // }

    for(int i = 0; i<length; i++){
        if(strcmp(data[i]->ma_mon_hoc, mon_hoc->ma_mon_hoc) > 0){
            this->move(i);
            data[i] = mon_hoc;
            length++;
            return;
        }
    }
    data[length++] = mon_hoc;
}

void DanhSachMonHoc::output(){
    printf("%d\n",length);
    for(int i = 0; i<length;  i++){
        printf("%s      %s\n", data[i]->ma_mon_hoc, data[i]->ten_mon_hoc.c_str());
    }
}