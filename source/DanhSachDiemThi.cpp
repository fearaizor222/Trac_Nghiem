#include "../header/DanhSachDiemThi.h"
#include "../header/DanhSachSinhVien.h"
#include "../header/DanhSachLop.h"
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
    
void DanhSachDiemThi::insertFirst(DiemThi dt){
    DTPtr p = new DiemThiNode;
    p->data = dt;
    p->next = First;
    First = p;
}

//Hàm thêm điểm thi vào sau nút địa chỉ First
void DanhSachDiemThi::insertAfterDT (DiemThi dt, DTPtr p){
    DTPtr q;
    if (p == NULL){
        cout << "Khong the them phan tu vao danh sach" << endl;
    } else {
        q = new DiemThiNode;
        q->data = dt;
        q->next = p->next;
        p->next = q;
    }
}

// Hàm kiểm tra xem môn học đã thi chưa
bool DanhSachDiemThi::kiemTraDaThi(DTPtr First,char Mamh[15]){
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

// Hàm đếm số môn học đã thi
// int DanhSachDiemThi::demMonHocDaThi(DTPtr First){
//     int dem = 0;
//     DTPtr sub_node;
//     sub_node = new DiemThiNode;
//     sub_node = First;
//     while(sub_node != NULL){
//         if(sub_node->data.Diem != -1){
//             dem++;
//         }
//         sub_node = sub_node->next;
//     }
//     return dem;
// }

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

void DanhSachDiemThi::xuatFileDanhSachDiemThi(){
    ofstream out("../data/DIEMTHI.txt", ios::app); // Mở file DiemThi.csv để ghi
    if (!out) {
        cout << "Khong mo duoc file";
        return;
    }
    DTPtr p = First;
    while (p != NULL) {
        out << p->data.Mamh << "|"; 
        if (kiemTraDaThi(First ,p->data.Mamh) == false) {
            out << "Chua thi"; // Nếu chưa thi thì ghi "Chua thi"
        } else {
            out << p->data.Diem; 
        }
        out << endl;
        p = p->next;
    }
    out.close();
}


// Hàm in điểm theo lớp
void DanhSachDiemThi::xuatDiemTheoLop(DanhSachSinhVien &list, char *Malop){
    ofstream out;

    char filename[50];
    char dinhdang[5];
    //Định dạng và tên file
    strcpy(dinhdang, ".txt");
    strcpy(filename, "../data/DIEM_");
    //Nối tên file với mã lớp dạng (VD: DIEM_D21CQCN02-N.csv) 
    strcat(filename, Malop);
    strcat(filename, dinhdang);
    out.open(filename, ios::app);
    if (!out) {
        cout << "Khong mo duoc file";
        return;
    }
    DanhSachSinhVien::SVPtr p = list.getFirst();
    while (p != NULL) {

        out << p->sv_data.MASV << "|" ;
        out << p->sv_data.HO << " " << p->sv_data.TEN << "|";

        // if (DanhSachDiemThi::demMonHocDaThi(p->sv_data.ptr) != 0){
            DTPtr q = First;
        while (q != NULL){
            out << q->data.Mamh << "|";
            // if (DanhSachDiemThi::kiemTraDaThi(p->sv_data.ptr,q->data.Mamh) == false) {
            //     out << "Chua thi"; // Nếu chưa thi thì ghi "Chua thi"
            // } else {
                out << q->data.Diem; 
            // }
            out << endl;
            q = q->next;
            }
        // }
        p = p->next;
    }
    out.close();
}