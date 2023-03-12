#include "..\header\DanhSachDiemThi.h"
#include "..\header\DanhSachMonHoc.h"
using namespace std;

DanhSachDiemThi::DanhSachDiemThi(){
    // khoiTaoDTPtr(&First);
    First = nullptr;
}

DanhSachDiemThi::~DanhSachDiemThi(){
    DTPtr p = First;
    while(p != NULL){
        DTPtr q = p;
        p = p->next;
        delete q;
    }
}

// void DanhSachDiemThi::khoiTaoDTPtr(DTPtr *First){
//     *First = NULL;
// }
    
void DanhSachDiemThi::insertFirst(DiemThi dt){
    DTPtr p = new DiemThiNode;
    p->data = dt;
    p->next = First;
    First = p;
}

//Hàm thêm điểm thi vào sau nút địa chỉ First
void DanhSachDiemThi::insertAfterDT (DiemThi dt, DTPtr First){
    DTPtr p;
    if (First == NULL){
        cout << "Khong the them phan tu vao danh sach" << endl;
    } else {
        p = new DiemThiNode;
        p->data = dt;
        p->next = First->next;
        First->next = p;
    }
}

// Hàm kiểm tra xem môn học đã thi chưa
bool DanhSachDiemThi::kiemTraDaThi(char Mamh[15]){
    DTPtr node_chay;
    node_chay = new DiemThiNode;
    node_chay = First;
    while(node_chay != NULL){
        if(strcmp(node_chay->data.Mamh, Mamh) == 0){
            return true;
        }
        node_chay = node_chay->next;
    }
    return false;
}

void DanhSachDiemThi::insertDiem(DTPtr &First, DiemThi dt){
    if (First==NULL){
        insertFirst(dt);
    }
    else {
        DTPtr p;
        p = new DiemThiNode;
        p = First;
        while(p->next != NULL){
            p = p->next;
        }
        insertAfterDT(dt, p);
    }
}

void DanhSachDiemThi::xuatDanhSachDiemThi() {
    ofstream out("../data/DiemThi.csv", ios::app); // Mở file DiemThi.csv để ghi
    if (!out) {
        cout << "Khong mo duoc file";
        return;
    }
    // Khởi chạy dòng đầu chỉ ở lần đầu tiên
    static int count = 0;
    if (count == 0) {
        out << "Ma mon hoc" << "," << "Diem" << endl;
    }

    DTPtr p = First;
    while (p != NULL) {
        out << p->data.Mamh << ","; 
        if (kiemTraDaThi(p->data.Mamh) == false) {
            out << "Chua thi"; // Nếu chưa thi thì ghi "Chua thi"
        } else {
            out << p->data.Diem; 
        }
        out << endl;
        p = p->next;
    }
    out.close();
}
