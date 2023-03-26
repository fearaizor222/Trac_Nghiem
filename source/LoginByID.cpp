#include "../header/LoginByID.h"
bool search(SVPtr FirstSV,string masv) {
        SVPtr* current = FirstSV;
        while (current != nullptr) {
            if (current->sv_data == masv) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
void login(string tendangnhap, string matkhau){
    if(tendangnhap=="GV" && matkhau=="GV"){
        ListClasses::hieuChinh(); 
    }
}