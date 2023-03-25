#include "../header/LoginByID.h"
    bool search(SVPtr sv,string masv) {
        SVPtr* current = FirstSV;
        while (current != nullptr) {
            if (current->sv_data == masv) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
bool user(){
    char tendangnhap[10], matkhau[8];
    scanf("%s",tendangnhap);
    scanf("%s",matkhau);
    for(int i=0;;i++){

    }
    if(tendangnhap=="GV" && matkhau=="GV"){
         return 0;
    }else return 1;
}

void login(){
    if(user()==0){
        ListClasses::hieuChinh(); 
    }
}