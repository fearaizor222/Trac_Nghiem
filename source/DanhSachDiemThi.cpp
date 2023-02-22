#include "header\DanhSachDiemThi.h"
#include <iostream>

Score::Score(string Mamh, float Diem)
{
    this->Mamh = Mamh;
    this->Diem = Diem;
}

Score::Score(Score *score)
{
    *this = *score;
}

string Score::getMamh()
{
    return Mamh;
}

void Score::setMamh(string Mamh)
{
    this->Mamh = Mamh;
}

float Score::getDiem()
{
    return Diem;
}

void Score::setDiem(float Diem)
{
    this->Diem = Diem;
}

ofstream &operator<<(ofstream &out, Score *score)
{
    out << score->Mamh << endl;
    out << score->Diem << endl;
    return out;
}

istream &operator>>(istream &in, Score *score)
{
    in >> score->Mamh;
    in >> score->Diem;
    return in;
}

ostream &operator<<(ostream &out, Score *score)
{
     if(score->Diem == -1) {
        out << "Chua thi"; //In ra "Chưa thi" nếu sinh viên chưa thi
    } else {
        out << score->Mamh << " " << score->Diem << endl;
    } 
    return out;
}

Score::Score()
{
}

Score::~Score()
{
}

ScoreNode::ScoreNode(Score data)
{
    this->data = data;
    this->next = NULL;
}

ScoreNode::ScoreNode()
{
}

ScoreNode::~ScoreNode()
{
}

ScoreList::ScoreList()
{
    first = NULL;
}

ScoreList::get_score_at_position(int index) //Lấy điểm tại vị trí index
{
    ScoreNode *p = first;
    int i = 0;
    while (p != NULL)
    {
        if (i == index)
        {
            return p->data;
        }
        p = p->next;
        i++;
    }
}

ScoreList::~ScoreList()
{
}





