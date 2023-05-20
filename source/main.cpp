#include "../header/raylib.h"
#include "../header/UserInterface.h"
#include "../header/Helper.h"

void MainSceneSV(SinhVien *&sv, DanhSachMonHoc &dsmh, DanhSachCauHoi &dsch)
{
    const int MAIN_SV_WIDTH = 1500;
    const int MAIN_SV_HEIGHT = 800;
    int page = 1;
    int index = 0;
    SetWindowSize(MAIN_SV_WIDTH, MAIN_SV_HEIGHT);
    SetWindowPosition(GetMonitorWidth(0)/2 - MAIN_SV_WIDTH/2, GetMonitorHeight(0)/2 - MAIN_SV_HEIGHT/2);
    InputBox input_ma_mon{{0, 0, 200, 50}, BLACK, BLUE, LIGHTGRAY, font, false};
    Rectangle box = {5, 100, 1490, 600};
    Button next{{BotRight().x - 110, BotRight().y - 90, 100, 50}, "Next", WHITE, BLUE, font};
    Button prev{{BotRight().x - 220, BotRight().y - 90, 100, 50}, "Prev", WHITE, BLUE, font};
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;

    while(!is_close_icon_pressed){
        BeginDrawing();
            ClearBackground(WHITE);

            next.run(is_button_next_pressed);
            prev.run(is_button_prev_pressed);
            if(is_button_next_pressed && page < dsmh.getLength() / 7 + 1) page++;
            if(is_button_prev_pressed && page > 1) page--;
            index = 7 * (page - 1);

            input_ma_mon.run(global_mouse_pos, TopLeft, 150, 50);
            DrawRectangleLinesEx(box, 3, BLACK);
            if(input_ma_mon.text.data == "" && !input_ma_mon.clicked)
                DrawTextEx(font, "Mã môn", (Vector2){input_ma_mon.box.x + 50, input_ma_mon.box.y + 10}, 30, 0, BLACK);

            for(int i = 0; i < 8; i++){
                DrawLineEx(Vector2{5, 175 + 75 * i}, Vector2{1490, 175 + 75 * i}, 2, BLACK);
            }

            DrawTextEx(font, "STT", {(5 + 100)/2 - (MeasureTextEx(font, "STT", 30, 3).x / 2), 124}, 30, 3, BLACK);
            DrawTextEx(font, "Mã môn", {(100 + 273)/2 - (MeasureTextEx(font, "Mã môn", 30, 3).x / 2), 124}, 30, 3, BLACK);
            DrawTextEx(font, "Tên môn học", {786 - (MeasureTextEx(font, "Tên môn học", 30, 3).x / 2), 124}, 30, 3, BLACK);
            DrawTextEx(font, "Điểm", {(1300 + 1490)/2 - (MeasureTextEx(font, "Điểm", 30, 3).x / 2), 124}, 30, 3, BLACK);
            DrawLineEx({100, 100}, {100, 700}, 2, BLACK);
            DrawLineEx({273, 100}, {273, 700}, 2, BLACK);
            DrawLineEx({1300, 100}, {1300, 700}, 2, BLACK);


            for (int place = 0; index < 7 * page && index < dsmh.getLength(); index++, place++)
            {
                DTPtr dt = nullptr;
                dt = (*sv->diem)[string(dsmh[index].ma_mon_hoc)];
                std::string output_mark;
                if(dt == nullptr){
                    output_mark = "Chưa thi";
                }
                else{
                    output_mark = std::to_string(dt->data.Diem).substr(0, std::to_string(dt->data.Diem).find(".") + 2);
                }
                DrawTextEx(font, std::to_string(index + 1).c_str(), {(5 + 100) / 2 - (MeasureTextEx(font, std::to_string(index + 1).c_str(), 30, 3).x / 2), 199 + 75 * place}, 30, 3, BLACK);
                DrawTextEx(font, dsmh[index].ma_mon_hoc, Vector2{100 + 5, 199 + 75 * place}, 30, 3, BLACK);
                DrawTextEx(font, (char *)dsmh[index].ten_mon_hoc.c_str(), Vector2{273 + 5, 199 + 75 * place}, 30, 3, BLACK);
                DrawTextEx(font, (char*)output_mark.c_str(), Vector2{(1490 + 1300)/2 - MeasureTextEx(font, (char*)output_mark.c_str(), 30, 3).x/2, 199 + 75 * place}, 30, 3, BLACK);
            }
        EndDrawing();

        if (WindowShouldClose())
        {
            is_close_icon_pressed = true;
        }

        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }

        is_button_next_pressed = false;
        is_button_prev_pressed = false;
    }
}

void GiaoDienDanhSachLop(){
    const int screenWidth = 1500;
    const int screenHeight = 800;
 //   int khoangcach = 160; 
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
 
    while(!is_close_icon_pressed){
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

        DrawTextEx(font, "Nhập từ khóa tìm kiếm",{47.5,20},20,3,GRAY);
        DrawTextEx(font,"--Chọn niên khóa--",{390,17.5},25,3,BLACK);
        DrawTextEx(font,"--Chọn lớp học--",{745,17.5},25,3,BLACK);
        DrawTextEx(font,"Tìm kiếm",{1050,17.5},25,3,WHITE);
        DrawTextEx(font,"MENU",{1240,15},30,3,WHITE);


        for(int i=0;i<3;i++){
            if(i!=2){
                DrawRectangle(10+(150*i),55,80,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,80,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),55,300,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,300,40,BLACK);
            }
        }
        DrawTextEx(font,"Thêm",{20,62.5},25,3,WHITE);
        DrawTextEx(font,"Xóa",{180,62.5},25,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{340,62.5},25,3,WHITE);
        for(int j=1;j<13;j++){
            if(j==1){
                for(int i=0;i<3;i++){
                DrawRectangle(0,100,80,50,BLUE);
                DrawRectangle(80+(480*i),100,480,50,BLUE);
                DrawRectangleLines(0,100*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 100*j, 480, 50, BLACK);
                }
            }else if(j>=3){
            for(int i=0;i<3;i++){
                DrawRectangleLines(0,50*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 50*j, 480, 50, BLACK);
            }
            }
        }
        DrawRectangleLines(600,700,100,40,BLACK);
        DrawRectangleLines(800,700,100,40,BLACK);
        DrawRectangle(600,700,100,40,Fade(BLUE,0.3f));
        DrawRectangle(800,700,100,40,Fade(BLUE,0.3f));
        DrawTextEx(font,"Trang trước",{604,712},15,3,BLACK);
        DrawTextEx(font,"Trang sau",{810,712},15,3,BLACK);
        DrawTextEx(font,"STT",{15,110},30,3,BLACK);
        DrawTextEx(font,"Mã lớp",{270,110},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{750,110},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1230,110},30,3,BLACK);
        // for(int i=1;i<11;i++){
        //     DrawTextEx(font,ListClasses[i]->getMaLop,{33,khoangcach},30,3,BLACK);
        //     khoangcach+=50;
        // }
        // cs = 50;
        EndDrawing();

        if (WindowShouldClose())
        {
            is_close_icon_pressed = true;
        }

        if(IsKeyPressed(KEY_ESCAPE)){
            break;
        }
    }
}
int main()
{
     Initialize();

    DanhSachLopHoc dslh("../data/DANHSACHLOP.txt");
    DanhSachMonHoc dsmh("../data/DANHSACHMON.txt");
    DanhSachCauHoi dsch("../data/DANHSACHCAUHOI.txt");
    SinhVien *sv = nullptr;

    current_scene = scene_stack.pop();
    while (current_scene != Exit || is_close_icon_pressed)
    {
        switch (current_scene)
        {
        case Login:
            LoginScene(dslh, sv);
            // std::cout<<(sv == nullptr)<<std::endl;
            current_scene = scene_stack.pop();
            break;

        case Main_SV:
            MainSceneSV(sv, dsmh, dsch);
            current_scene = scene_stack.pop();
            break;

        case Main_GV:
            GiaoDienDanhSachLop();
            current_scene = scene_stack.pop();
            break;

        case Testing:
            // TestingScene(dsch);
            current_scene = scene_stack.pop();
            break;

        case Exit:
            goto exit_tag;
        }
    }
    exit_tag:
   Deinitialize();
   return 0;

}



