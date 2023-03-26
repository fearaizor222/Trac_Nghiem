#include "../header/LoginByID.h"
bool search(DanhSachSinhVien::SVPtr FirstSV,string masv, string matkhau) {
        DanhSachSinhVien::SVPtr current = FirstSV;
        while (current!=nullptr){
            if(current->sv_data.MASV==masv && current->sv_data.password==matkhau) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

void login(string tendangnhap, string matkhau){
    DanhSachSinhVien::SVPtr FirstSV;
    if(tendangnhap=="GV" && matkhau=="GV"){

    }else if(tendangnhap!="GV" || matkhau!="GV"){
        if(search(FirstSV,tendangnhap,matkhau)==true){

        }else cout<<"Ten dang nhap hoac matkhau khong dung"<<endl;
    }
}