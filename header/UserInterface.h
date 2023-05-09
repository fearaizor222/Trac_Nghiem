#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "raylib.h"
#include <string>
#include <cstring>
#include "DArray.h"
#include "HashMap.h"
#include "Stack.h"

#define SIZE_DASH_NORMAL 15
#define FONT_PATH "../style/TimesNewRoman.ttf"
#define LOGO_PATH "../style/240px-Logo_PTIT_University.png"
#define WIDTH 480
#define HEIGHT 640

extern Vector2 global_mouse_pos;
extern Font font;
extern Image logo;
extern Stack<Scene> scene_stack;
extern Scene current_scene;
extern bool is_close_icon_pressed;

static HashMap viet_key = {
    {"á", "a"}, {"à", "a"}, {"ả", "a"}, {"ã", "a"}, {"ạ", "a"}, {"ă", "a"}, {"â", "a"}, 
    {"ắ", "ă"}, {"ằ", "ă"}, {"ẳ", "ă"}, {"ẵ", "ă"}, {"ặ", "ă"},  
    {"ấ", "â"}, {"ầ", "â"}, {"ẩ", "â"}, {"ẫ", "â"}, {"ậ", "â"},
    {"đ", "d"},
    {"é", "e"}, {"è", "e"}, {"ẻ", "e"}, {"ẽ", "e"}, {"ẹ", "e"}, {"ê", "e"}, 
    {"ế", "ê"}, {"ề", "ê"}, {"ể", "ê"}, {"ễ", "ê"}, {"ệ", "ê"},
    {"í", "i"}, {"ì", "i"}, {"ỉ", "i"}, {"ĩ", "i"}, {"ị", "i"},
    {"ó", "o"}, {"ò", "o"}, {"ỏ", "o"}, {"õ", "o"}, {"ọ", "o"}, {"ơ", "o"}, {"ô", "o"}, 
    {"ố", "ô"}, {"ồ", "ô"}, {"ổ", "ô"}, {"ỗ", "ô"}, {"ộ", "ô"},
    {"ớ", "ơ"}, {"ờ", "ơ"}, {"ở", "ơ"}, {"ỡ", "ơ"}, {"ợ", "ơ"},
    {"ú", "u"}, {"ù", "u"}, {"ủ", "u"}, {"ũ", "u"}, {"ụ", "u"}, {"ư", "u"}, 
    {"ứ", "ư"}, {"ừ", "ư"}, {"ử", "ư"}, {"ữ", "ư"}, {"ự", "ư"},
    {"ý", "y"}, {"ỳ", "y"}, {"ỷ", "y"}, {"ỹ", "y"}, {"ỵ", "y"},
    {"Á", "A"}, {"À", "A"}, {"Ả", "A"}, {"Ã", "A"}, {"Ạ", "A"}, {"Ă", "A"},  {"Â", "A"}, 
    {"Ắ", "Ă"}, {"Ằ", "Ă"}, {"Ẳ", "Ă"}, {"Ẵ", "Ă"}, {"Ặ", "Ă"},
    {"Ấ", "Ă"}, {"Ầ", "Ă"}, {"Ẩ", "Ă"}, {"Ẫ", "Ă"}, {"Ậ", "Ă"},
    {"Đ", "D"},
    {"É", "E"}, {"È", "E"}, {"Ẻ", "E"}, {"Ẽ", "E"}, {"Ẹ", "E"}, {"Ê", "E"}, 
    {"Ế", "Ê"}, {"Ề", "Ê"}, {"Ể", "Ê"}, {"Ễ", "Ê"}, {"Ệ", "Ê"},
    {"Í", "I"}, {"Ì", "I"}, {"Ỉ", "I"}, {"Ĩ", "I"}, {"Ị", "I"},
    {"Ó", "O"}, {"Ò", "O"}, {"Ỏ", "O"}, {"Õ", "O"}, {"Ọ", "O"}, {"Ô", "O"}, {"Ơ", "O"}, 
    {"Ố", "Ô"}, {"Ồ", "Ô"}, {"Ổ", "Ô"}, {"Ỗ", "Ô"}, {"Ộ", "Ô"},
    {"Ớ", "Ơ"}, {"Ờ", "Ơ"}, {"Ở", "Ơ"}, {"Ỡ", "Ơ"}, {"Ợ", "Ơ"},
    {"Ú", "U"}, {"Ù", "U"}, {"Ủ", "U"}, {"Ũ", "U"}, {"Ụ", "U"}, {"Ư", "U"}, 
    {"Ứ", "Ư"}, {"Ừ", "Ư"}, {"Ử", "Ư"}, {"Ữ", "Ư"}, {"Ự", "Ư"},
    {"Ý", "Y"}, {"Ỳ", "Y"}, {"Ỷ", "Y"}, {"Ỹ", "Y"}, {"Ỵ", "Y"},            
};

void Initialize();
void Deinitialize();

int find(std::string str, char c);

Vector2 TopLeft();
Vector2 TopCenter();
Vector2 TopRight();

Vector2 MidLeft();
Vector2 MidCenter();
Vector2 MidRight();

Vector2 BotLeft();
Vector2 BotCenter();
Vector2 BotRight();

struct Text{
    std::string data;
    Color normal;
    Color highlight;
    Font font;
    int size;
    int spacing;
    DArray<int> text_layout;

    Text(std::string _data = "",
        Color _normal = BLACK,
        Color _highlight = BLACK,
        Font _font = GetFontDefault(), 
        int _size = 30,
        int _spacing = 5);

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0);

    Text& operator=(const Text& other);
};

struct InputBox{
    Rectangle box;              // Vị trí và kích cỡ
    Text text;                  // Chuỗi đã nhập
    int max_length;             // Số kí tự tối đa 
    bool clicked;               // Đã được ấn vào hay chưa
    Color background;           // Màu của cái hộp
    long long frames_count;     // Dùng để cho nhấp nháy con trỏ khi chưa nhập xong
    bool secure;                // InputBox có an toàn không, có thì che kí tự ghi ra
    Text secure_text;           // Chuỗi tượng trưng

    InputBox(Rectangle _box = {0, 0, 100, 100}, 
            Color _normal = BLACK, 
            Color _hightlight = RED, 
            Color _background = LIGHTGRAY,
            Font _font = GetFontDefault(),
            bool _secure = false);

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0);

    void run(Vector2 &mouse_pos, Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0);

    bool isBoxFull();
};

struct Button{
    Rectangle box;              // Vị trí và kích cỡ
    std::string label;          // Tên nút
    Color normal;               // Màu nút khi idle
    Color highlight;            // Màu nút khi hover/ấn
    Color background;           // Màu của nút
    Font font;                  // Font của tên nút

    Button(Rectangle _box = {0, 0, 100, 100},
        std::string _label = "",
        Color _normal = BLACK, 
        Color _hightlight = BLUE, 
        Font _font = GetFontDefault());

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0);

    void run(bool &clicked, Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0);
};

#endif