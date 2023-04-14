#include "../header/raylib.h"
#include "../header/UserInterface.h"
// #include "../header/DanhSachSinhVien.h"
// #include "../header/LoginByID.h"

const int WIDTH  = 480;
const int HEIGHT = 640;
const Image logo = LoadImage("../style/240px-Logo_PTIT_University.png");
Texture2D login_logo;
Font font;
Vector2 global_mouse_pos = {-1, -1};

void LoginScene(){
    Text ID("ID:", BLACK, BLACK, font, 30, 5);
    Text Pass("Pass:", BLACK, BLACK, font, 30, 5);
    InputBox box1({(WIDTH/2 - 225/2) - 8, (HEIGHT/2 - 50/2) + 100, 240, 50}, BLACK, BLACK, WHITE, font);
    InputBox box2({(WIDTH/2 - 225/2) - 8, (HEIGHT/2 - 50/2) + 160, 240, 50}, BLACK, BLACK, WHITE, font, true);
    Button button1({(WIDTH/2 - 150/2), (HEIGHT/2 - 50/2) + 220, 150, 50}, "login", LIGHTGRAY, GRAY, font);

    bool is_button1_clicked = false;

    SetTargetFPS(10);
    while(!WindowShouldClose()){
        int wid_win = GetRenderWidth();
        int hei_win = GetRenderHeight();

        BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(login_logo, wid_win/2 - 250/2 + 5, hei_win/2 - 50/2 - 240 + 50, WHITE);
            ID.render(MidCenter, -160, 100);
            Pass.render(MidCenter, -175, 160);
            box1.run(global_mouse_pos,MidCenter, 0, 100);
            box2.run(global_mouse_pos,MidCenter, 0, 160);
            button1.run(is_button1_clicked, MidCenter, 0, 220);
        EndDrawing();
    }

    UnloadFont(font);
    UnloadTexture(login_logo);
}

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Phần mềm trắc nghiệm");
    SetWindowIcon(logo);
    SetWindowMinSize(480, 640);
    login_logo = LoadTextureFromImage(logo);
    font = LoadFontEx("../style/TimesNewRoman.ttf", 30, 0, 8192);

    LoginScene();

    UnloadImage(logo);
    CloseWindow();
    return 0;
}
// #include <iostream>
// #include "../header/DanhSachCauHoi.h"
// // #include "../header/DanhSachMonHoc.h"

// int main(){
//     DanhSachCauHoi list("../data/DANHSACHCAUHOI.txt");
//     while(true){
//         list.output();
//         std::cout << "Nhap ID cau hoi: ";
//         int id;
//         std::cin >> id;
//         list.remove(id);
//     }
//     // DanhSachMonHoc list("../data/DANHSACHMON.txt");
//     // list.output();
//     return 0;
// }
