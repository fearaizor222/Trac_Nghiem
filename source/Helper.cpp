#include "../header/Helper.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

bool Number(char c){
    return c >= '0' && c <= '9';
}

bool Word(char c){
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c == ' ');
}

bool All(char c){
    return c >= 32 && c <= 126;
}

char* Input(bool (*funcptr)(char), bool secure, int64_t *convertible){
    char *str = (char*)malloc(MAX_LENGTH);
    int i = 0;
    int barrier;  // Có 2 công dụng, cản kí tự đặc biệt và lấy kí tự vừa bấm

    while((barrier = getch()) != ENTER){
        if (barrier == 0 || barrier == 224){
            getch();
            continue;
        }
        
        if(funcptr(barrier)) printf(secure? "X" : "%c" ,str[i++] = barrier);  // Hiện kí tự vừa bấm

        if(barrier == BACKSPACE && i > 0){  // xóa kí tự
            printf("\b \b");
            i--;
        }
    }

    str[i] = '\0';

    if(convertible != nullptr){  // Đổi char* thành số, dùng khi có truyền vào biến
        (*convertible) = -1;
        if(i != 0){
            i = 0;
            (*convertible) = 0;
            while(str[i + 1] != '\0'){
                (*convertible) += (str[i] - '0');
                (*convertible) *= 10;
                i++;
            }
            (*convertible) += (str[i] - '0');
        }
    }
    return str;
}