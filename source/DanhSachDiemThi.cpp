#include "..\header\DanhSachDiemThi.h"
using namespace std;

DanhSachDiemThi::DanhSachDiemThi(){ // Hàm khởi tạo
    khoiTaoDTPtr(&First);

    ofstream out("DiemThi.csv", ios::out); // Tạo file DiemThi.csv
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma mon hoc"<<","<<"Diem"<<endl;
    inDiemRaFile(First, out);
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

void DanhSachDiemThi::khoiTaoDTPtr(DTPtr *First){
    *First = NULL;
}
    
void DanhSachDiemThi::inDiemRaFile(DTPtr First, ofstream &out){
    DTPtr p = First;
    while(p != NULL){
        if (p->data.Diem == -1){ // Nếu thí sinh chưa thi thì in ra chưa thi
            out<<p->data.Mamh<<","<<"Chua thi"<<endl;
            p = p->next;
        }
        else{
        out<<p->data.Mamh<<","<<p->data.Diem<<endl;
        p = p->next;
        }
    }
}

void DanhSachDiemThi::nhapDiemVaoTuFile(DTPtr *First, ifstream &in){ //For test case only, I will remove after test case is done
    char temp[100];
    in.getline(temp, 100); // Bỏ dòng đầu tiên
    while(!in.eof()){
        DTPtr p = new DiemThiNode;
        in.getline(p->data.Mamh, 15, ',');
        in>>p->data.Diem;
        in.ignore();
        p->next = *First;
        *First = p;
    }
    in.close();
}
