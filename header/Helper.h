#ifndef HELPER_H
#define HELPER_H

#include <cstdint>

#define ENTER 13
#define BACKSPACE 8
#define MAX_LENGTH 50
#define RANDOM 5000

/*
Tạo thuvien.h có các CTC sau:
-	NhapSo (…) : chỉ nhận số, nếu ký tự nhập không phải là ký số thì không nhận.
-	NhapChuoi: chỉ nhận chữ cái, blank.
-	NhapMa(): XXXXXXX, X : chữ cái in, chữ số, _. Ký tự bắt đầu là chữ cái
*/

extern bool Number(char);  // 3 hàm điều kiện, cho nhập số, chuỗi và toàn bộ kí tự, trừ kí tự đặc biệt
extern bool Word(char);
extern bool All(char);

extern char* Input(bool (*funcptr)(char) = All, bool secure = false, int64_t *convertible = nullptr);
                // Hàm điều kiện                hiện chữ hoặc giấu        tham chiếu khi cần lấy số

extern int rrand(int value);

extern void random();

extern void randomID();

#endif