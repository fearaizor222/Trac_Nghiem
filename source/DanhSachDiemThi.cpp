#include "../header/DanhSachDiemThi.h"
#include "../header/DanhSachSinhVien.h"
#include "../header/DanhSachLop.h"
using namespace std;


DanhSachDiemThi::DanhSachDiemThi(){
    // khoiTaoDTPtr(&First);
    First = nullptr;
    _path = "";
}

DanhSachDiemThi::DanhSachDiemThi(string path){
    First = nullptr;
    _path = path;
    ifstream in(_path);
    if (!in){
        ofstream out(_path);
        out.close();
        in.open(_path);
    }

    string line = "";
    while(getline(in, line)){
        stringstream ss(line);
        string _maMon, _diem;
        getline(ss, _maMon, '|');
        getline(ss, _diem, '|');
        insertFirst(DiemThi((char*)_maMon.c_str(), stof(_diem)));
    }
    in.close();
}

DanhSachDiemThi::DanhSachDiemThi(const DanhSachDiemThi &dsdt){
    First = nullptr;
    _path = dsdt._path;
    DTPtr p = dsdt.First;
    while(p != nullptr){
        insertFirst(p->data);
        p = p->next;
    }
}

DanhSachDiemThi& DanhSachDiemThi::operator=(const DanhSachDiemThi &dsdt){
    if(this == &dsdt){
        return *this;
    }

    this->~DanhSachDiemThi();
    First = nullptr;
    _path = dsdt._path;
    DTPtr p = dsdt.First;
    while(p != nullptr){
        insertFirst(p->data);
        p = p->next;
    }
    return *this;
}

string DanhSachDiemThi::getPath(){
    return _path;
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
    if (p == NULL){
        cout << "Khong the them phan tu vao danh sach" << endl;
        return;
    } else {
        DTPtr q = new DiemThiNode;
        q->data = dt;
        q->next = p->next;
        p->next = q;
        // p = q; //Cập nhật con trỏ đến nút mới chèn vào
    }
}

// Hàm kiểm tra xem môn học đã thi chưa
bool DanhSachDiemThi::kiemTraDaThi(DTPtr First,char Mamh[15]){
    DTPtr p;
    p = new DiemThiNode;
    p = First;
    while(p != NULL){
        if(strcmp(p->data.Mamh, Mamh) == 0){
            return true;
        }
        p = p->next;
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
            if (q->next != NULL){
                out << "|";
            }
            q = q->next;
            }
        // }
        out << endl;
        p = p->next;
    }
    out.close();
}