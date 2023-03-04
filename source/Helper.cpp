#include "../header/Helper.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define ENTER 13
#define BACKSPACE 8
#define MAX_LENGTH 50

int NhapSo(){
    char *number = (char*)malloc(50);
    int i = 0;

    while((number[i] = getch()) != ENTER){
        if(number[i] >= '0' && number[i] <= '9'){
            printf("%c",number[i]);
            i++;
        }
        if(number[i] == BACKSPACE && i > 0){
            printf("\b \b");
            number[i--] = '\0';
        }
    }
    long long tong = -1;
    
    if(i != 0){
        number[i] = '\0';
        i = 0;
        tong = 0;
        while(number[i + 1] != '\0'){
            tong += (number[i] - '0');
            tong *= 10;
            i++;
        }
        tong += (number[i] - '0');
    }

    free(number);
    return tong;
}

char *NhapChuoi(){
    char *str = (char*)malloc(MAX_LENGTH);
    int i = 0;
    int barrier;

    while((barrier = getch()) != ENTER){
        if (barrier == 0 || barrier == 224){
            getch();
            continue;
        }
        
        str[i] = barrier;
        if((str[i] >= 'a' && str[i] <= 'z') || 
            (str[i] >= 'A' && str[i] <= 'Z') ||
            str[i] == ' '){
            printf("%c",str[i]);
            i++;
        }
        if(str[i] == BACKSPACE && i > 0){
            printf("\b \b");
            str[i--] = '\0';
        }
    }

    str[i] = '\0';
    return str;
}

char *NhapMa(){
    char *str = (char*)malloc(MAX_LENGTH);
    int i = 0;
    int barrier;

    while((barrier = getch()) != ENTER ){
        if (barrier == 0 || barrier == 224){
            getch();
            continue;
        }

        str[i] = barrier;
        if( (str[0] >= 'a' && str[0] <= 'z' && i == 0) ||
            (str[i] >= 'A' && str[i] <= 'Z' && i != 0) || 
            (str[i] >= '0' && str[i] <= '9' && i != 0) ||
            str[i] == '_'  && i != 0){
            printf("X");
            i++;
        }
        if(str[i] == BACKSPACE && i > 0){
            printf("\b \b");
            str[i--] = '\0';
        }
    }

    str[i] = '\0';
    return str;
}