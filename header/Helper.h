#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <fstream>
#include <cstdint>

#define ENTER 13
#define BACKSPACE 8
#define MAX_LENGTH 50

extern bool Number(char);  
extern bool Word(char);
extern bool All(char);

extern char* Input(bool (*funcptr)(char) = All, bool secure = false, int64_t *convertible = nullptr);

#endif