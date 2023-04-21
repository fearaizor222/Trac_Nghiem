#ifndef DARRAY_H
#define DARRAY_H

class DArray
{
    public:
        DArray();
        ~DArray();
        DArray(const DArray &other);
        DArray& operator=(const DArray &other);
        void push_back(int value);
        void pop_back();
        int back();
        int size();
        void resize(int new_size);

    private:
        int *data;
        int capacity;
        int count;
};

#endif