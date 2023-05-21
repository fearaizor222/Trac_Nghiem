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
            DrawRectangle(10+(340*i),10,320,40,WHITE);
            DrawRectangleLines(10+(340*i),10,320,40,BLACK);
           }else if(i==3){
            DrawRectangle(1030,10,140,40,DARKBLUE);
            DrawRectangleLines(1030,10,140,40,BLACK);
           }else if(i==4){
            DrawRectangle(1350,10,120,40,DARKBLUE);
            DrawRectangleLines(1350,10,120,40,BLACK);
           }
        }

        DrawTextEx(font, "Nhập từ khóa tìm kiếm",{20,15},30,3,GRAY);
        DrawTextEx(font,"--Chọn niên khóa--",{380,15},30,3,BLACK);
        DrawTextEx(font,"--Chọn lớp học--",{735,15},30,3,BLACK);
        DrawTextEx(font,"Tìm kiếm",{1040,15},30,3,WHITE);
        DrawTextEx(font,"MENU",{1367.5,15},30,3,WHITE);


        for(int i=0;i<3;i++){
            if(i!=2){
                DrawRectangle(10+(150*i),55,80,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,80,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),55,300,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,300,40,BLACK);
            }
        }
        DrawTextEx(font,"Thêm",{13.5,60},30,3,WHITE);
        DrawTextEx(font,"Xóa",{174.5,60},30,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{325,60},30,3,WHITE);
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
        DrawTextEx(font,"STT",{15,110},30,3,BLACK);
        DrawTextEx(font,"Mã lớp",{270,110},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{750,110},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1210,110},30,3,BLACK);
        DrawRectangle(480,700,170,40,Fade(BLUE,0.2f));
        DrawRectangle(850,700,170,40,Fade(BLUE,0.2f));
        DrawRectangleLines(480,700,170,40,BLACK);
        DrawRectangleLines(850,700,170,40,BLACK);
        DrawTextEx(font,"Trang trước",{485,705},30,3,BLACK);
        DrawTextEx(font,"Trang sau",{870,705},30,3,BLACK);
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
void GiaoDienDanhSachSinhVien(){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  
         for(int i=0;i<5;i++){
           if(i<2){
            DrawRectangle(10+(390*i),10,350,40,WHITE);
            DrawRectangleLines(10+(390*i),10,350,40,BLACK);
           }else if(i==2){
            DrawRectangle(10+(390*i),10,280,40,WHITE);
            DrawRectangleLines(10+(390*i),10,280,40,BLACK);
           }else if(i==3){
            DrawRectangle(1100,10,140,40,DARKBLUE);
            DrawRectangleLines(1100,10,140,40,BLACK);
           }else if(i==4){
            DrawRectangle(1350,10,120,40,DARKBLUE);
            DrawRectangleLines(1350,10,120,40,BLACK);
           }
        }
        DrawTextEx(font, "Nhập từ khóa tìm kiếm",{32.5,15},30,3,GRAY);
        DrawTextEx(font,"Nhập mã số sinh viên",{432.5,15},30,3,BLACK);
        DrawTextEx(font,"--Chọn niên khóa--",{805,15},30,3,BLACK);
        DrawTextEx(font,"Tìm kiếm",{1105,15},30,3,WHITE);
        DrawTextEx(font,"MENU",{1367.5,15},30,3,WHITE);
        for(int i=0;i<3;i++){
            if(i!=2){
                DrawRectangle(10+(150*i),55,90,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,90,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),55,300,40,DARKBLUE);
                DrawRectangleLines(10+(150*i),55,300,40,BLACK);
            }
        }
        DrawTextEx(font,"Thêm",{18.5,60},30,3,WHITE);
        DrawTextEx(font,"Xóa",{179.5,60},30,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{325,60},30,3,WHITE);
        
        DrawRectangle(0,100,55,40,DARKBLUE);//STT
        DrawRectangle(55,100,170,40,DARKBLUE);//MSSV
        DrawRectangle(225,100,350,40,DARKBLUE);//Họ tên
        DrawRectangle(575,100,80,40,DARKBLUE);//Giới tín
        DrawRectangle(655,100,140,40,DARKBLUE);//Ngày sinh
        DrawRectangle(795,100,170,40,DARKBLUE);//Lớp
        DrawRectangle(965,100,370,40,DARKBLUE);//Tên lớp
        DrawRectangle(1335,100,170,40,DARKBLUE);//Niên khóa
    for(int i=0;i<=15;i++){
        if(i==0){
        DrawRectangleLines(0,100,55,40,BLACK);//STT
        DrawRectangleLines(55,100,170,40,BLACK);//MSSV
        DrawRectangleLines(225,100,350,40,BLACK);//Họ tên
        DrawRectangleLines(575,100,80,40,BLACK);//Giới tính
        DrawRectangleLines(655,100,140,40,BLACK);//Ngày sinh
        DrawRectangleLines(795,100,170,40,BLACK);//Lớp
        DrawRectangleLines(965,100,370,40,BLACK);//Tên lớp
        DrawRectangleLines(1335,100,170,40,BLACK);//Niên khóa   
        }else if(i>=1){
        DrawRectangleLines(0,100+40*i,55,40,BLACK);//STT
        DrawRectangleLines(55,100+40*i,170,40,BLACK);//MSSV
        DrawRectangleLines(225,100+40*i,350,40,BLACK);//Họ tên
        DrawRectangleLines(575,100+40*i,80,40,BLACK);//Giới tính
        DrawRectangleLines(655,100+40*i,140,40,BLACK);//Ngày sinh
        DrawRectangleLines(795,100+40*i,170,40,BLACK);//Lớp
        DrawRectangleLines(965,100+40*i,370,40,BLACK);//Tên lớp
        DrawRectangleLines(1335,100+40*i,170,40,BLACK);//Niên khóa   
        } 
    }
        DrawTextEx(font,"STT",{0,105},30,3,BLACK);
        DrawTextEx(font,"MSSV",{95,105},30,3,BLACK);
        DrawTextEx(font,"Họ và tên",{340,105},30,3,BLACK);
        DrawTextEx(font,"Phái",{585,105},30,3,BLACK);
        DrawTextEx(font,"Ngày sinh",{660,105},30,3,BLACK);
        DrawTextEx(font,"Lớp",{855,105},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{1105,105},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1355,105},30,3,BLACK);
        DrawRectangle(480,750,170,40,Fade(BLUE,0.2f));
        DrawRectangle(850,750,170,40,Fade(BLUE,0.2f));
        DrawRectangleLines(480,750,170,40,BLACK);
        DrawRectangleLines(850,750,170,40,BLACK);
        DrawTextEx(font,"Trang trước",{485,755},30,3,BLACK);
        DrawTextEx(font,"Trang sau",{870,755},30,3,BLACK);
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



