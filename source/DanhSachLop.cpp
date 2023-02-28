#include "../header/DanhSachLop.h"
Lop::Lop(){
    malop = tenlop = "N/A";
    nienkhoa = 0;
}
void Lop::setMaLop(string malop){
    this->malop = malop;
}
string Lop::getMaLop(){
    return malop;
}
void Lop::setTenLop(string tenlop){
    this->tenlop = tenlop;
}
string Lop::getTenLop(){
    return tenlop;
}
void Lop::setNienKhoa(int nienkhoa){
    this->nienkhoa = nienkhoa;
}
int Lop::getNienKhoa(){
    return nienkhoa;
}
danhSachLopHoc::danhSachLopHoc(){
    soluong = -1;
}
// danhSachLopHoc::~danhSachLopHoc(){
//     delete [] List;
// }
void ListClasses::init(){
    for(int i=0;i<soluong;i++){
        List[i] = new Lop();
    }
}
void ListClasses::setSoLuong(int soluong){
    this->soluong = soluong;
}
int ListClasses::getSoLuong(){
    return soluong;
}
void ListClasses::insertList(){
    string a; int b;
    for(int i=0;i<soluong;i++){
        printf("Nhap thong tin lop %d: \n",i+1);
        cout<<"Ma lop: ";
            getline(cin,a); 
            List[i]->setMaLop(a);
            cout<<endl;
        cout<<"Ten lop: ";
            getline(cin,a);
            List[i]->setTenLop(a);
            cout<<endl;
        cout<<"Nien khoa: ";
            cin>>b;
            List[i]->setNienKhoa(b);
            cout<<endl;
    }
}


