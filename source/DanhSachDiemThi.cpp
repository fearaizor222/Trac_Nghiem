#include "..\header\DanhSachDiemThi.h"
using namespace std;

DanhSachDiemThi::DanhSachDiemThi(){ // Hàm khởi tạo
    // khoiTaoDTPtr(&First);
    First = nullptr;

    ofstream out("../data/DiemThi.csv", ios::out); // Tạo file DiemThi.csv
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma mon hoc"<<","<<"Diem"<<endl;
    out.close();
}

DanhSachDiemThi::~DanhSachDiemThi(){ // Hàm hủy
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

void DanhSachDiemThi::insertLast (DiemThi dt){
    DTPtr p = new DiemThiNode;
    p->data = dt;
    p->next = NULL;
    if(First == NULL){
        First = p;
    }else{
        DTPtr q = First;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}

//Hàm kiểm tra xem môn học đã thi chưa
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

// void DanhSachDiemThi::insertDiem(){
//         cout << "Nhap diem: ";
//         cin >> dt.Diem;
//         DTPtr p = First;
//         while (p != NULL) {
//             if (strcmp(p->data.Mamh, dt.Mamh) == 0) {
//                 p->data.Diem = dt.Diem;
//                 break;
//             }
//             p = p->next;
//         }
// }

void DanhSachDiemThi::xuatDanhSachDiemThi() {
    ofstream out("../data/DiemThi.csv", ios::out); // Mở file DiemThi.csv để ghi
    if (!out) {
        cout << "Khong mo duoc file";
        return;
    }
    out << "Ma mon hoc" << "," << "Diem" << endl;
    DTPtr p = First;
    while (p != NULL) {
        out << p->data.Mamh << ","; 
        if (p->data.Diem == -1) {
            out << "Chua thi"; // Nếu chưa thi thì ghi "Chua thi"
        } else {
            out << p->data.Diem; 
        }
        out << endl;
        p = p->next;
    }
    out.close();
}
