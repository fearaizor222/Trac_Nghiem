#include "../header/DanhSachSinhVien.h"

DanhSachSinhVien::SinhVien::SinhVien(){
     MASV = HO = TEN = password = "";
     Phai = -1;

}
DanhSachSinhVien::SinhVien::SinhVien(string MASV, string HO, string TEN, bool Phai, string password){
    this->MASV = MASV;
    this->HO = HO;
    this->TEN = TEN;
    this->password = password;
    this->Phai = Phai;
}
DanhSachSinhVien::SinhVien::Date::Date(){
    ngay = thang = nam = -1;
}
DanhSachSinhVien::SinhVien::Date::Date(int ngay, int thang, int nam){
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}
DanhSachSinhVien::DanhSachSinhVien(){
    FirstSV = nullptr;
}
DanhSachSinhVien::~DanhSachSinhVien(){ 
    SVPtr p = FirstSV;
    while(p != NULL){
        SVPtr q = p;
        p = p->next;
        delete q;
    }
}
// void DanhSachSinhVien::inSinhVienRaFile(SVPtr FirstSV){
//     ofstream out("../data/DANHSACHSINHVIEN.csv", ios::out); 
//     if(!out){
//         cout<<"Khong mo duoc file";
//         return;
//     }
//     out<<"Ma Sinh Vien"<<","<<"Ho"<<","<<"Ten"<<","<<"Phai"<<";"<<"Password"<<endl;
//     SVPtr p = FirstSV;
//     while( p!=NULL ){
//         out<<p->sv_data.MASV<<p->sv_data.HO<<p->sv_data.TEN<<p->sv_data.Phai<<endl;
//         p = p->next;
//     }
//     out.close();
// }
void DanhSachSinhVien::insertFirst(SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->sv_data = sv;
    p->next = FirstSV;
    FirstSV = p;
}
void DanhSachSinhVien::insertLast(SinhVien sv){
    SVPtr p = new SinhVienNode;
    p->sv_data = sv;
    p->next = NULL;
    if(FirstSV==NULL){
        FirstSV = p;
        return;
    }
    SVPtr temp = FirstSV;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = p;
}
DanhSachSinhVien::DanhSachSinhVien(std::string path) : DanhSachSinhVien(){
    string rawline = "";
    ifstream input(path);
    while(getline(input, rawline)){
        string Ma_SV = rawline.substr(0, rawline.find("|"));
        string Ho = rawline.substr(rawline.find("|") + 1, rawline.size() - 1);
        string Ten = rawline.substr(rawline.find("|")+ 1, rawline.size() - 1 );
        string PHAI = rawline.substr(rawline.find("|"+ 1), rawline.size() - 1);
        string PASSWORD = rawline.substr(rawline.find("|"+ 1), rawline.size() - 1);
        bool Gender = (PHAI=="Nam")?1:0;

        insert(SinhVien(Ma_SV, Ho, Ten, Gender, PASSWORD));
    }
}
void DanhSachSinhVien::insert(SinhVien sinh_vien){
    for(int i = 0; i<length; i++){
        if(FirstSV->sv_data.MASV.compare(sinh_vien.MASV) > 0){
            this->move(i, 1);
            data[i] = sinh_vien;
            length++;
            return;
        } 
    } 
    data[length++] = sinh_vien;
}

// void DanhSachSinhVien::move(int index, int offset){
//     if(offset == 1){
//         SinhVien temp1 = data[index];
//         for(int i = index + offset; i <= length; i++){
//             SinhVien temp2 = data[i];
//             data[i] = temp1;
//             temp1 = temp2;
//         }
//     }
//     else{
//         SinhVien temp1 = data[length - 1];
//         for(int i = length - 2; i >= index; i--){
//             SinhVien temp2 = data[i];
//             data[i] = temp1;
//             temp1 = temp2;
//         }
//     }
// }
