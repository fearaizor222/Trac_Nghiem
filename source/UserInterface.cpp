#include "../header/UserInterface.h"
#include <iostream>
#include "../header/Helper.h"

Vector2 global_mouse_pos;
Font font;
Image logo;
Stack<Scene> scene_stack;
Scene current_scene;
bool is_close_icon_pressed;

void Initialize(){
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Phần mềm trắc nghiệm");
    
    global_mouse_pos = {-1, -1};
    scene_stack.push(Exit);
    scene_stack.push(Login);
    is_close_icon_pressed = false;

    font = LoadFontEx(FONT_PATH, 30, 0, 8192);
    logo = LoadImage(LOGO_PATH);

    SetWindowIcon(logo);
    SetWindowMinSize(480, 640);
    SetTargetFPS(10);

    SetExitKey(KEY_NULL);
}

void Deinitialize(){
    UnloadFont(font);
    UnloadImage(logo);
    CloseWindow();
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
    return {(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f};
}

Vector2 MidRight(){
    return {(float)GetScreenWidth(), (float)GetScreenHeight()/2.0f};
}

Vector2 BotLeft(){
    return {0, (float)GetScreenHeight()};
}

Vector2 BotCenter(){
    return {(float)GetScreenWidth()/2.0f, (float)GetScreenHeight()};
}

Vector2 BotRight(){
    return {(float)GetScreenWidth(), (float)GetScreenHeight()};
}

Text::Text(std::string _data,
        Color _normal,
        Color _highlight,
        Font _font, 
        int _size,
        int _spacing){
    data = _data;
    normal = _normal;
    highlight = _highlight;
    font = _font;
    size = _size;
    spacing = _spacing;
}

void Text::render(Vector2 (*location)(), int offset_x, int offset_y){
    Vector2 size_text = MeasureTextEx(font, data.c_str(), size, spacing);
    Vector2 default_location = location();
    Vector2 final_des;

    final_des.x = default_location.x - (size_text.x)/2 + offset_x;
    final_des.y = default_location.y - (size_text.y)/2 + offset_y;

    DrawTextEx(font, data.c_str(), final_des, size, spacing, normal);
}

Text& Text::operator=(const Text& other){
    data = other.data;
    normal = other.normal;
    highlight = other.highlight;
    font = other.font;
    size = other.size;
    spacing = other.spacing;
    return *this;
}

InputBox::InputBox(Rectangle _box, 
            Color _normal, 
            Color _hightlight, 
            Color _background,
            Font _font,
            bool _secure){
    box = _box;
    max_length = -1;
    text = {"", _normal, _hightlight, _font};
    clicked = false;
    background = _background;
    frames_count = 0;
    secure = _secure;
    secure_text = {"", _normal, _hightlight, _font};
}

void InputBox::render(){  // Chỉ vẽ khung 
    if (clicked) frames_count++;
    else frames_count = 0;

    if (clicked){
        DrawRectangleRec(box, background);
        DrawRectangleLinesEx(box, 1, text.highlight);
    }
    else DrawRectangleLinesEx(box, 1, text.normal); 

    Text display_text;
    if(secure) display_text = secure_text;
    else display_text = text;

    Color text_color;
    if(clicked) text_color = text.highlight;
    else text_color = text.normal;
    
    if(isBoxFull() && display_text.data.length() > max_length){
        DrawTextEx(text.font, display_text.data.substr(display_text.data.length() - max_length).c_str(), {box.x + 5, box.y + 8}, text.size, text.spacing, text_color);
    }
    else{
        DrawTextEx(text.font, display_text.data.c_str(), {box.x + 5, box.y + 8}, text.size, text.spacing, text_color);
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

void InputBox::run(Vector2 &mouse_pos){
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
                uint64_t how_many_to_remove = find(text.data, viet_key[str_utf8][0]);
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
            
            if(isBoxFull() && max_length == std::string::npos) max_length = text.data.length();
            else if(!isBoxFull() && max_length != std::string::npos) max_length = std::string::npos;

            key = GetCharPressed();
        }

        if (IsKeyDown(KEY_BACKSPACE) && text.text_layout.size() > 0){
            while(text.text_layout.back() == 0) text.text_layout.pop_back();
            for(int i = 0; i < text.text_layout.back(); i++) text.data.pop_back();
            text.text_layout.pop_back();
            
            secure_text.data.pop_back();
        }
    }
    
    render();
}

bool InputBox::isBoxFull(){      
    Text display = secure? secure_text : text;  
    if(box.width - SIZE_DASH_NORMAL*2 <= MeasureTextEx(text.font, display.data.c_str(), text.size, text.spacing).x) return true;
    return false;
}

Button::Button(Rectangle _box,
        std::string _label,
        Color _normal, 
        Color _hightlight, 
        Font _font){
    box = _box;
    label = _label;
    normal = _normal;
    highlight = _hightlight;
    background = normal;
    font = _font;
}

void Button::render(){
    Vector2 size = MeasureTextEx(font, label.c_str(), 30, 5);
    DrawRectangleRec(box, background);
    DrawRectangleLines(box.x, box.y, box.width, box.height, BLACK);
    DrawTextEx(font, label.c_str(), {box.x + box.width/2 - size.x/2, box.y + box.height/2 - size.y/2}, 30, 5, BLACK);
}

void Button::run(bool &clicked){
    if(CheckCollisionPointRec(GetMousePosition(), box)){
        background = highlight;
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            clicked = true;
        }
    }
    else background = normal;

    render();
}

void LoginScene(DanhSachLopHoc &dslh, SinhVien *&sv)
{
    const int MAIN_SV_WIDTH = 480;
    const int MAIN_SV_HEIGHT = 640;
    SetWindowSize(MAIN_SV_WIDTH, MAIN_SV_HEIGHT);
    SetWindowPosition(GetMonitorWidth(0)/2 - MAIN_SV_WIDTH/2, GetMonitorHeight(0)/2 - MAIN_SV_HEIGHT/2);
    Texture2D login_logo = LoadTextureFromImage(logo);

    Text ID("ID:", BLACK, BLACK, font, 30, 5);
    Text Pass("Pass:", BLACK, BLACK, font, 30, 5);
    InputBox box1(Rectangle{(WIDTH / 2 - 225 / 2) - 8, (HEIGHT / 2 - 50 / 2) + 100, 240, 50}, BLACK, BLACK, WHITE, font);
    InputBox box2(Rectangle{(WIDTH / 2 - 225 / 2) - 8, (HEIGHT / 2 - 50 / 2) + 160, 240, 50}, BLACK, BLACK, WHITE, font, true);
    Button button1(Rectangle{(WIDTH / 2 - 150 / 2), (HEIGHT / 2 - 50 / 2) + 220, 150, 50}, "login", LIGHTGRAY, GRAY, font);

    bool is_button1_clicked = false;
    bool is_error = false;

    while (!is_close_icon_pressed)
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(login_logo, MidCenter().x - 250 / 2 + 5, MidCenter().y - 50 / 2 - 240 + 50, WHITE);
            ID.render(MidCenter, -160, 100);
            Pass.render(MidCenter, -175, 160);
            box1.run(global_mouse_pos);
            box2.run(global_mouse_pos);
            button1.run(is_button1_clicked);
            if (is_error)
            {
                string err;
                if (box1.text.data == "" || box2.text.data == "")
                {
                    err = "ID or Password is empty!";
                }
                else
                {
                    err = "ID or Password is wrong!";
                }
                Rectangle close_button = Popup(err, "Error");
                if (CheckCollisionPointRec(global_mouse_pos, close_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    is_error = false;
                    box1.text.data = "";
                    box2.text.data = "";
                    box2.secure_text.data = "";
                    box1.text.text_layout.clear();
                    box2.text.text_layout.clear();
                    box2.secure_text.text_layout.clear();
                }
            }
        EndDrawing();

        if (is_button1_clicked)
        {
            int res = login(dslh, sv, box1.text.data, box2.text.data);
            if (res == 2)
            {
                scene_stack.push(current_scene);
                scene_stack.push(Main_GV);
                break;
            }
            else if(res == 1)
            {
                scene_stack.push(current_scene);
                scene_stack.push(Main_SV);
                break;
            }
            else
            {
                is_error = true;
            }
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        if (WindowShouldClose())
            is_close_icon_pressed = true;

        is_button1_clicked = false;
    }

    UnloadTexture(login_logo);
}

Rectangle Popup(std::string message, std::string lable){
    Vector2 measure_msg = MeasureTextEx(font, (char *)message.c_str(), 30, 5);
    Vector2 measure_lable = MeasureTextEx(font, (char *)lable.c_str(), 30, 5);
    // measure.x = MidCenter().x - measure.x / 2;
    // measure.y = MidCenter().y - measure.y / 4;
    Rectangle main_popup = {MidCenter().x - 400 / 2, MidCenter().y - 300 / 2, 400, 300};
    Rectangle close_button = {main_popup.x + 350, main_popup.y, 50, 50};
    DrawRectangleRec(main_popup, WHITE);
    DrawRectangleRec(close_button, RED);
    DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
    DrawRectangleLines(main_popup.x, main_popup.y, main_popup.width, main_popup.height, BLACK);
    DrawLine(main_popup.x, main_popup.y + 50, main_popup.x + main_popup.width, main_popup.y + 50, BLACK);
    DrawLine(main_popup.x + 350, main_popup.y, main_popup.x + 350, main_popup.y + 50, BLACK);
    DrawTextEx(font, (char *)message.c_str(), Vector2{main_popup.x + main_popup.width/2 - measure_msg.x/2, main_popup.y + main_popup.height/2 - measure_msg.y/2}, 30, 5, BLACK);
    DrawTextEx(font, (char*)lable.c_str(), Vector2{main_popup.x + main_popup.width/2 - measure_lable.x/2, (main_popup.y * 2 + 50)/2 - measure_lable.y/2}, 30, 5, BLACK);

    return close_button;
}