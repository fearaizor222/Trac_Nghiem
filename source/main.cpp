#include "../header/raylib.h"
#include "../header/UserInterface.h"
// #include "../header/DanhSachSinhVien.h"
// #include "../header/LoginByID.h"

void LoginScene(){
    Texture2D login_logo = LoadTextureFromImage(logo);

    Text ID("ID:", BLACK, BLACK, font, 30, 5);
    Text Pass("Pass:", BLACK, BLACK, font, 30, 5);
    InputBox box1({(WIDTH/2 - 225/2) - 8, (HEIGHT/2 - 50/2) + 100, 240, 50}, BLACK, BLACK, WHITE, font);
    InputBox box2({(WIDTH/2 - 225/2) - 8, (HEIGHT/2 - 50/2) + 160, 240, 50}, BLACK, BLACK, WHITE, font, true);
    Button button1({(WIDTH/2 - 150/2), (HEIGHT/2 - 50/2) + 220, 150, 50}, "login", LIGHTGRAY, GRAY, font);

    bool is_button1_clicked = false;

    while(!is_button1_clicked){
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

        if(WindowShouldClose()){
            current_scene = Exit;
            break;
        }
    }

    if(current_scene != Exit) current_scene = Main;

    UnloadTexture(login_logo);
}

int main(){
    Initialize();

    while(current_scene != Exit){
        switch(current_scene){
            case Login:
                LoginScene();
                break;

            case Main:
                BeginDrawing();
                    ClearBackground(WHITE);
                    DrawText("Main", 10, 10, 20, BLACK);
                EndDrawing();

                if(IsKeyPressed(KEY_ESCAPE)){
                    current_scene = Login;
                }
                break;

            case Exit:
                break;
        }
    }

    Deinitialize();
    return 0;
}