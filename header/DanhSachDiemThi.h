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
    Score get_score_at_position (int index); //Lấy điểm tại vị trí index

    ScoreList();
    ~ScoreList();
};