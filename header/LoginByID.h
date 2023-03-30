#ifndef LOGINBYID_H
#define LOGINBYID_H
#include <iostream>
#include <string>
#include <string.h>
#include "DanhSachLop.h"
#include "../header/DanhSachSinhVien.h"
extern bool search(DanhSachSinhVien::SVPtr FirstSV ,string masv, string matkhau);
extern void login(string tendangnhap, string matkhau);
bool soSanh(string s1, string s2, int index);
#endif
