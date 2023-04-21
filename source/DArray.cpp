#include "../header/DArray.h"
#include <iostream>

DArray::DArray()
{
    data = new int[1];
    capacity = 1;
    count = 0;
}

DArray::DArray(const DArray &other)
{
    data = new int[other.capacity];
    capacity = other.capacity;
    count = other.count;
    for (int i = 0; i < count; i++)
    {
        data[i] = other.data[i];
    }
}

DArray& DArray::operator=(const DArray &other)
{
    if (this != &other)
    {
        delete[] data;
        data = new int[other.capacity];
        capacity = other.capacity;
        count = other.count;
        for (int i = 0; i < count; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

DArray::~DArray()
{
    delete[] data;
}

void DArray::resize(int new_size){
    int *temp = new int[new_size];

    count = new_size > count? count : new_size;
    for (int i = 0; i < count; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = new_size;
}

void DArray::push_back(int value)
{
    if (count == capacity)
    {
        resize(capacity * 2);
    }
    data[count] = value;
    count++;
}

void DArray::pop_back()
{
    if (count > 0)
    {
        count--;
    }
}

int DArray::back()
{
    return data[count - 1];
}

int DArray::size()
{
    return count;
}

