#pragma once
#include <cstdint>

/*
Tạo thuvien.h có các CTC sau:
-	NhapSo (…) : chỉ nhận số, nếu ký tự nhập không phải là ký số thì không nhận.
-	NhapChuoi: chỉ nhận chữ cái, blank.
-	NhapMa(): XXXXXXX, X : chữ cái in, chữ số, _. Ký tự bắt đầu là chữ cái
*/

extern uint64_t NhapSo();
extern char *NhapChuoi();
extern char *NhapMa();