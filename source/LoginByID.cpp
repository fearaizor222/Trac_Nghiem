#include "../header/LoginByID.h"
bool search(DanhSachSinhVien::SVPtr FirstSV,string masv) {
        DanhSachSinhVien::SVPtr current = FirstSV;
        while (current!=nullptr){
            if(current->sv_data.MASV==masv) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
bool searchPW(DanhSachSinhVien::SVPtr FirstSV, string password){
        DanhSachSinhVien::SVPtr current = FirstSV;
        while(current!=nullptr){
            if(current->sv_data.password==password){
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
        if(searchID(FirstSV, tendangnhap)==false && searchPW(FirstSV, matkhau)==false){
            cout<<"Ten dang nhap hoac mat khau khong dung"<<endl;
        }else if(searchID(FirstSV,tendangnhap)==true && searchPW(FirstSV,matkhau)==false){
            cout<<"Sai mat khau"<<endl;
        }else if(searchID(FirstSV,tendangnhap)==true && searchPW(FirstSV,matkhau)==true){
            
        }
    }
}