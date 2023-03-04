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
    ofstream out("../data/DANHSACHLOP.csv", ios::out);
    if(!out){
        cout<<"Khong mo duoc file";
        return;
    }
    out<<"Ma Lop"<<","<<"Ten Lop"<<","<<"Nien Khoa"<<endl;
    out.close();
}
 danhSachLopHoc::~danhSachLopHoc(){
    for(int i=0;i<soluong;i++){
        delete List[i];
    }
 }
void ListClasses::setSoLuong(int soluong){
    this->soluong = soluong;
}
int ListClasses::getSoLuong(){
    return soluong;
}
void ListClasses::insertList(Lop *List[], int &soluong){
    string a; int b;
    for(int i=0;i<soluong;i++){
        printf("Nhap thong tin lop %d: \n",i);
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
void ListClasses::inLopRaFile(Lop *List[]){
    ofstream out("../data/DANHSACHLOP.csv", ios::out); // Mở file Diemthi.csv để ghi
    if (!out) {
        cout << "Khong mo duoc file";
        return;
    }
    out<<"Ma Lop"<<","<<"Ten Lop"<<","<<"Nien Khoa"<<endl;
    for(int i=0;i<soluong;i++){
        out<<List[i]->getMaLop()<<","<<List[i]->getTenLop()<<","<<List[i]->getNienKhoa();
    }
    out.close();
}
void ListClasses::themLopVaoDanhSach(Lop *List[], int &soluong){
        int soluongcanthem, b;
        string a;
        cin>>soluongcanthem;
        soluong+=soluongcanthem;
        for(int i=soluong-soluongcanthem;i<soluong;i++){
        printf("Nhap thong tin lop %d: \n",i);
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
void ListClasses::xoaLopTrongDanhSach(Lop *List[], int &soluong){
        string malopcanxoa;
        cout<<"Nhap ma lop can xoa: ";
        getline(cin,malopcanxoa);
        for(int i=0;i<soluong;i++){
            if(malopcanxoa==List[i]->getMaLop()){
               for(int j=i;j<soluong;j++){
                List[j]=List[j+1];
               }
            }
        }
        soluong--;
}
void ListClasses::inLopTheoNienKhoa(Lop *List[]){
    int nienkhoaCanIn;
    cout<<"Nhap nien khoa can in: ";
    cin>>nienkhoaCanIn;
    for(int i=0;i<soluong;i++){
        if(nienkhoaCanIn==List[i]->getNienKhoa()){
            cout<<List[i]->getMaLop()<<" "<<List[i]->getTenLop()<<" "<<List[i]->getNienKhoa()<<endl;
        }
    }
}


