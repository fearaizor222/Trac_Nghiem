#include "../header/LoginByID.h"
bool search(DanhSachSinhVien::SVPtr FirstSV,string masv, string matkhau) {
        DanhSachSinhVien::SVPtr current = FirstSV;
        while (current!=nullptr){
            if(soSanh(current->sv_data.MASV,masv,0)==true && soSanh(current->sv_data.password,matkhau,0)==true) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
bool soSanh(string s1, string s2, int index){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(index==s1.length()){
            return true;
        }
        if(s1[index]==s2[index]){
            return soSanh(s1,s2,index+1);
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