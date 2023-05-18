#include "../header/DanhSachSinhVien.h"

SinhVien::SinhVien(){
    MASV = HO = TEN = Phai = password = "";
    diem = nullptr;
}

SinhVien::SinhVien(string MASV, string HO, string TEN, string Phai, string password){
    this->MASV = MASV;
    this->HO = HO;
    this->TEN = TEN;
    this->Phai = Phai;
    this->password = password;
    this->diem = new DanhSachDiemThi("../data/DSDT/" + MASV + ".txt");
}

SinhVien::SinhVien(const SinhVien &sv)
{
    this->MASV = sv.MASV;
    this->HO = sv.HO;
    this->TEN = sv.TEN;
    this->Phai = sv.Phai;
    this->password = sv.password;
    this->diem = new DanhSachDiemThi(sv.diem->getPath());
}

SinhVien &SinhVien::operator=(const SinhVien &sv)
{
    this->MASV = sv.MASV;
    this->HO = sv.HO;
    this->TEN = sv.TEN;
    this->Phai = sv.Phai;
    this->password = sv.password;
    this->diem = new DanhSachDiemThi(sv.diem->getPath());
    return *this;
}

void SinhVien::insert(DiemThi dt){
    diem->insertFirst(dt);
}

DiemThi &SinhVien::operator[](string _maMH){
    return (*diem)[_maMH];
}

SinhVien::~SinhVien(){
    delete diem;
}

DanhSachSinhVien::DanhSachSinhVien(){
    FirstSV = nullptr;
}

DanhSachSinhVien::~DanhSachSinhVien(){
    update();

    SVPtr p = FirstSV;
    while(p != NULL){
        SVPtr q = p;
        p = p->next;
        delete q;
    }
}

SVPtr &DanhSachSinhVien::getFirst(){
    return FirstSV;
}

SinhVien &DanhSachSinhVien::operator[](string _MASV){
    SVPtr p = FirstSV;
    while(p != NULL){
        if(strcmp(p->sv_data.MASV.c_str(),_MASV.c_str()) == 0){
            return p->sv_data;
        }
        p = p->next;
    }
    throw "Không tìm thấy sinh viên";
}

void DanhSachSinhVien::insertFirst(SinhVien sv){
     SVPtr p = new SinhVienNode;
    p->sv_data = sv;
    p->next = FirstSV;
    FirstSV = p;
}

void DanhSachSinhVien::insertAfter(SVPtr p, SinhVien sv){
    if(p==NULL){
        cout<<"Khong the them vao vi tri nay";
        return;
    }
    SVPtr q = new SinhVienNode;
    q->sv_data = sv;
    q->next = p->next;
    p->next = q;
}

void DanhSachSinhVien::insertLast(SinhVien sv){
    if (FirstSV == NULL){
        insertFirst(sv);
        return;
    }
    else{
        SVPtr p = new SinhVienNode;
        p=FirstSV;
        while(p->next!=NULL){
            p=p->next;
        }
        insertAfter(p, sv);
    }
}

void DanhSachSinhVien::insertOrderSV(SVPtr &FirstSV, SinhVien sv, string MASV){
    SVPtr s, t;
    SVPtr p = new SinhVienNode;
    p->sv_data = sv;

    //Tìm vị trí chèn
    for (s = FirstSV; s != NULL && strcmp(s->sv_data.MASV.c_str(),MASV.c_str()) != 0; t = s, s = s->next);

    //Chèn vào đầu danh sách
    if (s == FirstSV){
        p->next = FirstSV;
        FirstSV = p;
    }
    //Chèn vào cuối danh sách
    else{
        p->next = s;
        t->next = p;
    }
}

//Xoá SV theo mã sinh viên
void DanhSachSinhVien::deleteSV(string MASV){
    SVPtr p = FirstSV;
    SVPtr q = NULL;
    while(p != NULL){
        if(strcmp(p->sv_data.MASV.c_str(),MASV.c_str()) == 0){
            if(q == NULL){
                FirstSV = p->next;
                delete p;
                p = FirstSV;
            }
            else{
                q->next = p->next;
                delete p;
                p = q->next;
            }
        }
        else{
            q = p;
            p = p->next;
        }
    }
}

void DanhSachSinhVien::setPath(string path)
{
    this->path = path;
}

string DanhSachSinhVien::getPath()
{
    return path;
}

bool DanhSachSinhVien::isEmpty(){
    return FirstSV == NULL;
}

DanhSachSinhVien::DanhSachSinhVien(std::string path):DanhSachSinhVien(){
    this->path = path;
    ifstream input(this->path);
    if(!input.is_open()){
        ofstream output(this->path);
        output.close();
        return;
    }
    string line;
    while(getline(input,line)){
        stringstream _line(line);
        string Ma_SV, Ho, Ten, PHAI, PASSWORD;

        getline(_line,Ma_SV,'|');
        getline(_line,Ho,'|');
        Ten = Ho.substr(Ho.find(" ")+1);
        Ho = Ho.substr(0,Ho.find(" "));
        getline(_line,PHAI,'|');
        getline(_line,PASSWORD,'|');
        // string temp;
        // stringstream __line(PASSWORD);
        // PASSWORD = "";
        // while(getline(__line,temp,'/')) PASSWORD += temp;

        insertLast(SinhVien(Ma_SV, Ho, Ten, PHAI, PASSWORD));
    }
}

DanhSachSinhVien &DanhSachSinhVien::operator=(const DanhSachSinhVien &dssv){
    if(this == &dssv){
        return *this;
    }
    this->~DanhSachSinhVien();
    SVPtr p = dssv.FirstSV;
    path = dssv.path;
    while(p != NULL){
        insertLast(p->sv_data);
        p = p->next;
    }
    return *this;
}

DanhSachSinhVien::DanhSachSinhVien(const DanhSachSinhVien &dssv){
    SVPtr p = dssv.FirstSV;
    path = dssv.path;
    while(p != NULL){
        insertLast(p->sv_data);
        p = p->next;
    }
}

void DanhSachSinhVien::update(){
    ofstream output(path);
    SVPtr p = FirstSV;
    while(p != NULL){
        output << p->sv_data.MASV << "|" << p->sv_data.HO << " " << p->sv_data.TEN << "|" << p->sv_data.Phai << "|" << p->sv_data.password << endl;
        p = p->next;
    }
    output.close();
}