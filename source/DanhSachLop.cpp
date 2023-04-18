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
void ListClasses::insertList(int &soluong){
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
void ListClasses::inLopTheoNienKhoa(){
    int nienkhoaCanIn;
    cout<<"Nhap nien khoa can in: ";
    cin>>nienkhoaCanIn;
    for(int i=0;i<soluong;i++){
        if(nienkhoaCanIn==List[i]->getNienKhoa()){
            cout<<List[i]->getMaLop()<<" "<<List[i]->getTenLop()<<" "<<List[i]->getNienKhoa()<<endl;
        }
    }
}
void ListClasses::hieuChinh(){
    int lop, luachon1, luachon2, b;
    string a;
    do{
    cout<<"Nhap lua chon cua ban: "<<endl;
    cout<<"1-Them lop"<<endl;
    cout<<"2-Xoa Lop"<<endl;
    cout<<"3-Hieu chinh"<<endl;
    cout<<"4-Thoat"<<endl;
    switch(luachon1){
        case 1: ListClasses::themLopVaoDanhSach(List, soluong);
        break;
        case 2: ListClasses::xoaLopTrongDanhSach(List,soluong);
        break;
        case 3:
            cout<<"Nhap lop can hieu chinh: ";
            cin>>lop;
            do{
                cout<<"1-Ma Lop"<<endl;
                cout<<"2-Ten Lop"<<endl;
                cout<<"3-Nien Khoa"<<endl;
                cout<<"4-Thoat"<<endl;
            switch(luachon2){
            case 1: cout<<"Nhap ma lop: ";
                    getline(cin,a);
                    List[lop]->setMaLop(a);
                    cout<<endl;
                    break;
            case 2: cout<<"Nhap ten lop: ";
                    getline(cin,a);
                    List[lop]->setTenLop(a);
                    cout<<endl;
                    break;
            case 3: cout<<"Nhap nien khoa: ";
                    cin>>b;
                    List[lop]->setNienKhoa(b);
                    cout<<endl;
                    break;
            default:
                    cout<<"INVALID NUMBER"<<endl;
        }
    }while(luachon2==4);
        break;
        default: cout<<"INVALID NUMBER"<<endl;
    }
    }while(luachon1==4);
}
danhSachLopHoc::danhSachLopHoc(std::string path) : danhSachLopHoc(){
    string rawline = "";
    ifstream input(path);
    while(getline(input, rawline)){
        string MALOP = rawline.substr(0, rawline.find("|"));
        string TENLOP = rawline.substr(rawline.find("|") + 1, rawline.size() - 1);
        string NIENKHOA = rawline.substr(rawline.find("|")+ 1, rawline.size() - 1 );
        int NIEN_KHOA = stoi(NIENKHOA);
 //       insert(Lop(MALOP, TENLOP, NIEN_KHOA));
    }
}
void danhSachLopHoc::insert(Lop *lop_hoc, bool write_to_file){ 
    if(soluong == MAX_DSL){
        throw "Danh sách lớp đã đầy";
        return;
    }
    if(searchClass(lop_hoc->getMaLop() ) != -1){
        std::string error = "Mã lớp đã tồn tại: " + std::string(lop_hoc->getMaLop());
        throw error;
        return;
    } 
    if(write_to_file){
        update(lop_hoc);
    }
    for(int i = 0; i<soluong; i++){
        if(strcmp(List[i]->getMaLop().c_str(), lop_hoc->getMaLop().c_str()) > 0){
            this->move(i, 1);
            List[i] = lop_hoc;
            soluong++;
            return;
        }
    }
    List[soluong++] = lop_hoc;
}
void danhSachLopHoc::move(int index, int offset){
    if(offset == 1){
        Lop *temp1 = List[index];
        for(int i = index + offset; i <= soluong; i++){
            Lop *temp2 = List[i];
            List[i] = temp1;
            temp1 = temp2;
        }
    }
    else{
        Lop *temp1 = List[soluong - 1];
        for(int i = soluong - 2; i >= index; i--){
            Lop *temp2 = List[i];
            List[i] = temp1;
            temp1 = temp2;
        }
    }
}
int danhSachLopHoc::searchClass(string malop){
    for(int i = 0; i<soluong; i++){
        if(strcmp(List[i]->getMaLop().c_str(), malop.c_str()) == 0){
            return i;
        }
    }
    return -1;
}
void danhSachLopHoc::update(Lop *lop_hoc){
    std::ofstream output("../data/DANHSACHLOP.txt", std::ios::app);
    if(!output.is_open()){
        throw "Không thể mở file";
        return;
    }
    output<<lop_hoc<<std::endl;
    output.close();
}


