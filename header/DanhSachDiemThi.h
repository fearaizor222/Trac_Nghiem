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

    friend ofstream &operator<<(ofstream &out, Score *score);
    friend istream &operator>>(istream &in, Score *score);
    friend ostream &operator<<(ostream &out, Score *score);
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
    bool empty();
    int get_size();
    void insert(Score data);
    void remove();
    ScoreNode* get_score_from_subject(int index, DanhSachMonHoc *dsmh);

    ScoreList();
    ~ScoreList();
};