#ifndef LOGINBYID_H
#define LOGINBYID_H
#include <iostream>
#include <string>
#include <string.h>
#include "DanhSachLop.h"
#include "../header/DanhSachSinhVien.h"
extern bool searchID(DanhSachSinhVien::SVPtr FirstSV ,string masv, string matkhau);
extern void login(string tendangnhap, string matkhau);
#endif
