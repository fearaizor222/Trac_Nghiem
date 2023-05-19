#include "../header/raylib.h"
#include "../header/UserInterface.h"
//#include "../header/DanhSachSinhVien.h"
//#include "../header/LoginByID.h"

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
void GiaoDienDanhSachLop(){
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    InitWindow(screenWidth,screenHeight,"ListClassAfterClick");
    SetTargetFPS(60);
 
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  
        for(int i=0;i<5;i++){
           if(i<3){
            DrawRectangle(10+(340*i),10,300,40,WHITE);
            DrawRectangleLines(10+(340*i),10,300,40,BLACK);
           }else if(i==3){
            DrawRectangle(1030,10,140,40,DARKBLUE);
            DrawRectangleLines(1030,10,140,40,BLACK);
           }else if(i==4){
            DrawRectangle(1210,10,140,40,DARKBLUE);
            DrawRectangleLines(1210,10,140,40,BLACK);
           }
        }
        DrawText("Nhap tu khoa tim kiem",50,20,20,GRAY);
        DrawText("--Chon nien khoa--",400,20,20,BLACK);
        DrawText("--Chon lop hoc--",750,20,20,BLACK);
        DrawText("Tim kiem",1060,20,20,WHITE);
        DrawText("MENU",1250,20,20,WHITE);
        for(int i=0;i<3;i++){
            if(i!=2){
                DrawRectangle(10+(150*i),55,80,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,80,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),55,300,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,300,40,BLACK);
            }
        }
        DrawText("Them",20,65,20,WHITE);
        DrawText("Xoa",180,65,20,WHITE);
        DrawText("Hieu Chinh Thong Tin",360, 65,20,WHITE);
        for(int j=1;j<17;j++){
            if(j==1){
                for(int i=0;i<3;i++){
                DrawRectangle(0,100,80,50,BLUE);
                DrawRectangle(80+(480*i),100,480,50,BLUE);
                DrawRectangleLines(0,100*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 100*j, 480, 50, BLACK);
                }
            }else if(j>=3){
            for(int i=0;i<3;i++){
                DrawRectangleLines(0,100*j-(50*j),80,50,BLACK);
                DrawRectangleLines(80+(480*i), 100*j-(50*j), 480, 50, BLACK);
            }
            }
        }
        DrawText("STT",20,120,20,BLACK);
        DrawText("Mã lớp",290,120,20,BLACK);
        DrawText("Tên lớp",770,120,20,BLACK);
        DrawText("Niên khóa",1250,120,20,BLACK);

        DrawRectangleLines(600,900,100,40,BLACK);
        DrawRectangleLines(800,900,100,40,BLACK);
        DrawRectangle(600,900,100,40,Fade(BLUE,0.3f));
        DrawRectangle(800,900,100,40,Fade(BLUE,0.3f));
        DrawText("Previous",620,915,15,BLACK);
        DrawText("Next",830,915,15,BLACK);
        EndDrawing();
    }
    CloseWindow();
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