#pragma once

/*
Tạo thuvien.h có các CTC sau:
-	NhapSo (…) : chỉ nhận số, nếu ký tự nhập không phải là ký số thì không nhận.
-	NhapChuoi: chỉ nhận chữ cái, blank.
-	NhapMa(): XXXXXXX, X : chữ cái in, chữ số, _. Ký tự bắt đầu là chữ cái
-	VeKhung(x1,y1,x2,y2, kieu) ; kieu =1 thì HCN đơn, kieu =2 thì HCN kép
-	ThongBao (char* S, kieu); kieu =1 thì thông báo; kieu=2 thì có phản hồi của user.
*/

extern long long NhapSo();
extern char *NhapChuoi();
extern char *NhapMa();