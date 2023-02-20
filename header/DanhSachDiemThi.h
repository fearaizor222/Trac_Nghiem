#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "DanhSachMonHoc.h"

using namespace std;

class Score
{
private:
    string Mamh;
    float Diem;

public:
    Score(string Mamh, float Diem); 
    Score(Score *score);

    string getMamh();
    void setMamh(string Mamh);
    float getDiem();
    void setDiem(float Diem);

    friend ofstream &operator<<(ofstream &out, Score *score); //Ghi vào file
    friend istream &operator>>(istream &in, Score *score); //Đọc từ file
    friend ostream &operator<<(ostream &out, Score *score); //In ra màn hình
    Score();
    ~Score();
};

class ScoreNode
{
public:
    Score data;
    ScoreNode *next;

    ScoreNode(Score data);
    ScoreNode();
    ~ScoreNode();
};

class ScoreList
{
    ScoreNode *first;
    int size = 0;

public:
    bool empty(); //Kiểm tra danh sách có rỗng hay không
    int get_size(); //Lấy số lượng phần tử trong danh sách
    void insert_first(Score data); //Thêm phần tử vào đầu danh sách
    void insert_last(Score data); //Thêm phần tử vào cuối danh sách
    void insert_at(Score data, int index); //Thêm phần tử vào vị trí index
    void remove_byID (string Masv); //Xoá theo Mã sinh viên
    void remove_at(int index); //Xóa phần tử tại vị trí index
    ScoreNode* get_score_from_subject(int index, DanhSachMonHoc *dsmh); //Lấy điểm của môn học tại vị trí index
    Score get_score_at_position (int index); //Lấy điểm tại vị trí index


    ScoreList();
    ~ScoreList();
};