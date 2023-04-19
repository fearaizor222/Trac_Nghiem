#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "raylib.h"
#include <string>
#include <cstring>
#include <iostream>
#include "HashMap.h"
#include <vector>

#define SIZE_DASH_NORMAL 15
#define FONT_PATH "../style/TimesNewRoman.ttf"
#define LOGO_PATH "../style/240px-Logo_PTIT_University.png"
#define WIDTH 480
#define HEIGHT 640

enum Scene{
    Login = 0,
    Main,
    Exit
};

static Vector2 global_mouse_pos;
static Font font;
static Image logo;
static Scene current_scene;

HashMap viet_key = {
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

void Initialize(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Phần mềm trắc nghiệm");
    
    global_mouse_pos = {-1, -1};
    current_scene = Login;

    font = LoadFontEx(FONT_PATH, 30, 0, 8192);
    logo = LoadImage(LOGO_PATH);

    SetWindowIcon(logo);
    SetWindowMinSize(480, 640);
    SetTargetFPS(10);
}

void Deinitialize(){
    UnloadFont(font);
    UnloadImage(logo);
    CloseWindow();
}

int find(std::string str, char c){
    int index = std::string::npos;
    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] == ' '){
            return std::string::npos;
        }
        if(str[i] == c){
            if(c == 'u' || c == 'U'){
                for(int j = i - 1; j >= 0; j--){
                    if(str[j] == ' ') return i;
                    if(str[j] == c) return j;
                }
            }
            return i;
        }
    }
    return std::string::npos;
}

Vector2 TopLeft(){
    return {0, 0};
}

Vector2 TopCenter(){
    return {(float)GetScreenWidth()/2.0f , 0};
}

Vector2 TopRight(){
    return {(float)GetScreenWidth(), 0};
}

Vector2 MidLeft(){
    return {0, (float)GetScreenHeight()/2.0f};
}

Vector2 MidCenter(){
    return {(float)GetScreenWidth()/2.0f , (float)GetScreenHeight()/2.0f};
}

Vector2 MidRight(){
    return {(float)GetScreenWidth(), (float)GetScreenHeight()/2.0f};
}

Vector2 BotLeft(){
    return {0, (float)GetScreenHeight()};
}

Vector2 BotCenter(){
    return {(float)GetScreenWidth()/2.0f , (float)GetScreenHeight()};
}

Vector2 BotRight(){
    return {(float)GetScreenWidth(), (float)GetScreenHeight()};
}

struct Text{
    std::string data;
    Color normal;
    Color highlight;
    Font font;
    int size;
    int spacing;
    std::vector<int> text_layout;

    Text(std::string _data = "",
            Color _normal = BLACK,
            Color _highlight = BLACK,
            Font _font = GetFontDefault(), 
            int _size = 30,
            int _spacing = 5){
        data = _data;
        normal = _normal;
        highlight = _highlight;
        font = _font;
        size = _size;
        spacing = _spacing;
    }

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0){
        Vector2 size_text = MeasureTextEx(font, data.c_str(), size, spacing);
        Vector2 default_location = location();
        Vector2 final_des;

        final_des.x = default_location.x - (size_text.x)/2 + offset_x;
        final_des.y = default_location.y - (size_text.y)/2 + offset_y;

        DrawTextEx(font, data.c_str(), final_des, size, spacing, normal);
    }

    Text& operator=(const Text& other){
        data = other.data;
        normal = other.normal;
        highlight = other.highlight;
        font = other.font;
        size = other.size;
        spacing = other.spacing;
        return *this;
    }
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
                bool _secure = false){
        box = _box;
        max_length = -1;
        text = {"", _normal, _hightlight, _font};
        clicked = false;
        background = _background;
        frames_count = 0;
        secure = _secure;
        secure_text = {"", _normal, _hightlight, _font};
    }

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0){  // Chỉ vẽ khung
        box.x = location().x - box.width/2 + offset_x; 
        box.y = location().y - box.height/2 + offset_y; 
        if (clicked) frames_count++;
        else frames_count = 0;

        DrawRectangleRec(box, background);
        if (clicked) DrawRectangleLines((int)box.x, (int)box.y, (int)box.width, (int)box.height, text.highlight);
        else DrawRectangleLines((int)box.x, (int)box.y, (int)box.width, (int)box.height, text.normal);

        Text display_text;
        if(secure) display_text = secure_text;
        else display_text = text;
        
        if(isBoxFull() && display_text.data.length() > max_length){
            DrawTextEx(text.font, display_text.data.substr(display_text.data.length() - max_length).c_str(), {box.x + 5, box.y + 8}, text.size, text.spacing, text.highlight);
        }
        else{
            DrawTextEx(text.font, display_text.data.c_str(), {box.x + 5, box.y + 8}, text.size, text.spacing, text.highlight);
        }
        
        if(clicked){
            if(isBoxFull() && display_text.data.length() > max_length)
            {
                if(((frames_count/5)%2) == 0) DrawText("_", (int)box.x + 8 + MeasureTextEx(text.font, display_text.data.substr(display_text.data.length() - max_length).c_str(), text.size, text.spacing).x, (int)box.y + 12, text.size, text.highlight);
            }
            else{
                if(((frames_count/5)%2) == 0) DrawText("_", (int)box.x + 8 + MeasureTextEx(text.font, display_text.data.c_str(), text.size, text.spacing).x, (int)box.y + 12, text.size, text.highlight);
            }
        }
    }

    void run(Vector2 &mouse_pos, Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) mouse_pos = GetMousePosition();
    
        if (CheckCollisionPointRec(mouse_pos, box)) clicked = true;
        else clicked = false;

        if (clicked){
            int key = GetCharPressed();
            while (key > 0){
                int length = 0;
                const char * utf8 = CodepointToUTF8(key, &length);
                std::string str_utf8(utf8);
                str_utf8.resize(length);
                if(length > 1){ 
                    int how_many_to_remove = find(text.data, viet_key[str_utf8][0]);
                    if(how_many_to_remove == std::string::npos) how_many_to_remove = text.data.length();
                    text.data.resize(how_many_to_remove);
                    text.text_layout.resize(how_many_to_remove);
                }
                text.data += str_utf8;
                secure_text.data += '*';
                text.text_layout.push_back(length);
                if(length > 1){
                    for(int i = 0; i<length - 1; i++) text.text_layout.push_back(0);
                }
                
                if(isBoxFull() && max_length == -1) max_length = text.data.length();
                else if(!isBoxFull() && max_length != -1) max_length = -1;

                key = GetCharPressed();
            }

            if (IsKeyDown(KEY_BACKSPACE) && text.text_layout.size() > 0){
                while(text.text_layout.back() == 0) text.text_layout.pop_back();
                for(int i = 0; i < text.text_layout.back(); i++) text.data.pop_back();
                text.text_layout.pop_back();
                
                secure_text.data.pop_back();
            }
        }
        
        render(location, offset_x, offset_y);
    }

    std::string getText(){
        return text.data;
    }

    bool isBoxFull(){      
        Text display = secure? secure_text : text;  
        if(box.width - SIZE_DASH_NORMAL*2 <= MeasureTextEx(text.font, display.data.c_str(), text.size, text.spacing).x) return true;
        return false;
    }
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
            Font _font = GetFontDefault()){
        box = _box;
        label = _label;
        normal = _normal;
        highlight = _hightlight;
        background = normal;
        font = _font;
    }

    void render(Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0){
        box.x = location().x - box.width/2 + offset_x; 
        box.y = location().y - box.height/2 + offset_y; 
        Vector2 size = MeasureTextEx(font, label.c_str(), 30, 5);
        DrawRectangleRec(box, background);
        DrawRectangleLines(box.x, box.y, box.width, box.height, BLACK);
        DrawTextEx(font, label.c_str(), {box.x + size.x/2, box.y + size.y/2}, 30, 5, BLACK);
    }

    void run(bool &clicked, Vector2 (*location)() = TopLeft, int offset_x = 0, int offset_y = 0){
        if(CheckCollisionPointRec(GetMousePosition(), box)){
            background = highlight;
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                clicked = true;
            }
        }
        else background = normal;

        render(location, offset_x, offset_y);            
    }
};



#endif