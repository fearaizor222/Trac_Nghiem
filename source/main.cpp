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
    InputBox input_ma_mon{{25, 25, 200, 50}, BLACK, BLUE, LIGHTGRAY, font, false};
    InputBox box_thoi_gian_thi(Rectangle{MidCenter().x - 400 / 2 + 180, MidCenter().y - 300 / 2 + 110, 200, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_so_cau_hoi(Rectangle{MidCenter().x - 400 / 2 + 180, MidCenter().y - 300 / 2 + 170, 200, 50}, BLACK, BLACK, WHITE, font);
    Rectangle box = {5, 100, 1490, 600};
    Button next{{BotRight().x - 110, BotRight().y - 90, 100, 50}, "Next", WHITE, BLUE, font};
    Button prev{{BotRight().x - 220, BotRight().y - 90, 100, 50}, "Prev", WHITE, BLUE, font};

    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    bool press_flag = false;
    string ma_mon_chon_thi = "";
    string so_cau_thi = "";
    string thoi_gian_thi = "";

    global_mouse_pos = GetMousePosition();

    while(!is_close_icon_pressed){

        BeginDrawing();
            ClearBackground(WHITE);

            next.run(is_button_next_pressed);
            prev.run(is_button_prev_pressed);
            if(is_button_next_pressed && page < dsmh.getLength() / 7 + 1) page++;
            if(is_button_prev_pressed && page > 1) page--;
            index = 7 * (page - 1);

            input_ma_mon.run(global_mouse_pos);
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

            for (int place = 0, offset = 0; index < dsmh.getLength(); index++, place++)
            {
                if(input_ma_mon.text.data != ""){
                    if(strstr(dsmh[index].ma_mon_hoc, input_ma_mon.text.data.c_str()) == nullptr){
                        offset++;
                        continue;
                    }
                }
                Rectangle rec = {5, 175 + 75 * place, 1490, 75};
                DTPtr dt = nullptr;
                dt = (*sv->diem)[string(dsmh[index].ma_mon_hoc)];
                std::string output_mark;
                if(dt == nullptr){
                    output_mark = "Chưa thi";
                }
                else{
                    output_mark = std::to_string(dt->data.Diem).substr(0, std::to_string(dt->data.Diem).find(".") + 2);
                }
                DrawTextEx(font, std::to_string(index + 1 - offset).c_str(), {(5 + 100) / 2 - (MeasureTextEx(font, std::to_string(index + 1 - offset).c_str(), 30, 3).x / 2), 199 + 75 * (place - offset)}, 30, 3, BLACK);
                DrawTextEx(font, dsmh[index].ma_mon_hoc, Vector2{100 + 5, 199 + 75 * (place - offset)}, 30, 3, BLACK);
                DrawTextEx(font, (char *)dsmh[index].ten_mon_hoc.c_str(), Vector2{273 + 5, 199 + 75 * (place - offset)}, 30, 3, BLACK);
                DrawTextEx(font, (char*)output_mark.c_str(), Vector2{(1490 + 1300)/2 - MeasureTextEx(font, (char*)output_mark.c_str(), 30, 3).x/2, 199 + 75 * (place - offset)}, 30, 3, BLACK);

                if(CheckCollisionPointRec(GetMousePosition(), rec)){
                    DrawRectangleLinesEx(rec, 3, GREEN);

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_flag){
                        if(output_mark == "Chưa thi"){
                            press_flag = true;
                            ma_mon_chon_thi = dsmh[index].ma_mon_hoc;
                        }
                    }
                }
            }

            if(press_flag){
                Vector2 measure_lable = MeasureTextEx(font, (char*)ma_mon_chon_thi.c_str(), 30, 5);
                Rectangle main_popup = {MidCenter().x - 400 / 2, MidCenter().y - 300 / 2, 400, 300};
                Rectangle close_button = {main_popup.x + 350, main_popup.y, 50, 50};
                DrawRectangleRec(main_popup, WHITE);
                DrawRectangleRec(close_button, RED);
                DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                DrawRectangleLines(main_popup.x, main_popup.y, main_popup.width, main_popup.height, BLACK);
                DrawLine(main_popup.x, main_popup.y + 50, main_popup.x + main_popup.width, main_popup.y + 50, BLACK);
                DrawLine(main_popup.x + 350, main_popup.y, main_popup.x + 350, main_popup.y + 50, BLACK);
                // DrawTextEx(font, (char *)message.c_str(), Vector2{main_popup.x + main_popup.width / 2 - measure_msg.x / 2, main_popup.y + main_popup.height / 2 - measure_msg.y / 2}, 30, 5, BLACK);
                DrawTextEx(font, (char*)ma_mon_chon_thi.c_str(), Vector2{main_popup.x + main_popup.width / 2 - measure_lable.x / 2, (main_popup.y * 2 + 50) / 2 - measure_lable.y / 2}, 30, 5, BLACK);

                DrawTextEx(font, "Thời gian:", Vector2{main_popup.x + 20, main_popup.y + 120}, 30, 5, BLACK);
                DrawTextEx(font, "Số câu:", Vector2{main_popup.x + 20, main_popup.y + 180}, 30, 5, BLACK);

                box_thoi_gian_thi.run(global_mouse_pos);
                box_so_cau_hoi.run(global_mouse_pos);

                if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                    DrawRectangleRec(close_button, Fade(RED, 0.5f));

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_flag = false;
                    }
                }
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

void GiaoDienDanhSachLop(DanhSachLopHoc &dslh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
 //   int khoangcach = 160; 
    int page = 1;
    int index = 0;
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    Button next{{485,705,180,45},"Trang trước",Fade(BLUE,0.2f),BLUE,font};
    Button prev{{850,705,180,45},"Trang sau",Fade(BLUE,0.2f),BLUE,font};
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(RAYWHITE);
            next.run(is_button_next_pressed);
            prev.run(is_button_prev_pressed);
            if(is_button_next_pressed && page < 11) page++;
            if(is_button_prev_pressed && page > 1) page--;
            index = 10 * (page - 1);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  
        for(int i=0;i<5;i++){
           if(i<3){
            DrawRectangle(10+(340*i),10,320,40,WHITE);//Vẽ 3 ô: Nhập từ khóa, niên khóa, lớp học
            DrawRectangleLines(10+(340*i),10,320,40,BLACK);
           }else if(i==3){
            DrawRectangle(1030,10,140,40,DARKBLUE);//Ô tìm kiếm
            DrawRectangleLines(1030,10,140,40,BLACK);
           }else if(i==4){
            DrawRectangle(1350,10,120,40,DARKBLUE);//Ô menu
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
                DrawRectangle(10+(150*i),55,80,40,DARKBLUE);//ô thêm, xóa
                DrawRectangleLines(10+(150*i),55,80,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),55,300,40,DARKBLUE);// ô hiệu chỉnh
                DrawRectangleLines(10+(150*i),55,300,40,BLACK);
            }
        }
        DrawTextEx(font,"Thêm",{13.5,60},30,3,WHITE);
        DrawTextEx(font,"Xóa",{174.5,60},30,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{325,60},30,3,WHITE);
        for(int j=1;j<13;j++){
            if(j==1){
                for(int i=0;i<3;i++){
                  DrawRectangle(0,100,80,50,BLUE);//ô STT
                if(i==0){//mã lớp
                DrawRectangle(80+(260*i),100*j,260,50,BLUE);
                DrawRectangleLines(0,100*j,80,50,BLACK);
                DrawRectangleLines(80+(260*i), 100*j, 260, 50, BLACK);
                }else if(i==1){//Tên lớp
                DrawRectangle(80+(260*i),100*j,700,50,BLUE);
                DrawRectangleLines(0,100*j,80,50,BLACK);
                DrawRectangleLines(80+(260*i), 100*j, 700, 50, BLACK);
                }else{//Niên khóa
                DrawRectangle(80+(480*i),100*j,480,50,BLUE);
                DrawRectangleLines(0,100*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 100*j, 480, 50, BLACK);
                }
                }
            }else if(j>=3){
            for(int i=0;i<3;i++){
                if(i==0){//mã lớp
                DrawRectangleLines(0,50*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 50*j, 260, 50, BLACK);
                }else if(i==1){//tên lớp
                DrawRectangleLines(0,50*j,80,50,BLACK);//vẽ các khung đen
                DrawRectangleLines(80+(260*i), 50*j, 700, 50, BLACK);
                }else{//niên khóa
                DrawRectangleLines(0,50*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 50*j, 480, 50, BLACK);  
                }
               
            }
            }
        }
        
        DrawTextEx(font,"STT",{15,110},30,3,BLACK);
        DrawTextEx(font,"Mã lớp",{165,110},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{640,110},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1210,110},30,3,BLACK);
        for(int place = 0; index < 7 * page && index < dslh.getSoLuong(); index++, place++){
              DrawTextEx(font,to_string(index+1).c_str(),{30,160+70*place+20*(-place)},30,3,BLACK);//STT
              DrawTextEx(font,(char*)dslh[place]->getMaLop().c_str(),Vector2{90,160+70*place+20*(-place)},30,3,BLACK);// Mã lớp
              DrawTextEx(font,(char*)dslh[place]->getTenLop().c_str(),Vector2{350,160+70*place+20*(-place)},30,3,BLACK);//tên lớp
              DrawTextEx(font,(char*)dslh[place]->getNienKhoa().c_str(),Vector2{1200,160+70*place+20*(-place)},30,3,BLACK);//niên khóa
        }
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
void GiaoDienDanhSachSinhVien(DanhSachLopHoc &dslh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    int page = 1;
    int index = 0;
    SVPtr sv = dslh["D21CQAT01-N"]->getDSSV()->getFirst();
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    Button next{{480,750,180,45},"Trang trước",Fade(BLUE,0.2f),BLUE,font};
    Button prev{{850,750,180,45},"Trang sau",Fade(BLUE,0.2f),BLUE,font};
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(RAYWHITE);
            next.run(is_button_next_pressed);
            prev.run(is_button_prev_pressed);
            if(is_button_next_pressed && page < 16) page++;
            if(is_button_prev_pressed && page > 1) page--;
            index = 15 * (page - 1);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  //vẽ bản màu xám
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
        }//Vẽ 5 ô: Nhập từ khóa, nhập mã số sv, niên khóa, tìm kiếm và menu
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
        }// vẽ ô ở dưới: thêm, xóa, hiệu chỉnh
        DrawTextEx(font,"Thêm",{18.5,60},30,3,WHITE);
        DrawTextEx(font,"Xóa",{179.5,60},30,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{325,60},30,3,WHITE);
        
        DrawRectangle(0,100,55,40,DARKBLUE);//STT
        DrawRectangle(55,100,190,40,DARKBLUE);//MSSV
        DrawRectangle(245,100,370,40,DARKBLUE);//Họ tên
        DrawRectangle(615,100,80,40,DARKBLUE);//Giới tín
        DrawRectangle(695,100,195,40,DARKBLUE);//Lớp
        DrawRectangle(890,100,390,40,DARKBLUE);//Tên lớp
        DrawRectangle(1280,100,220,40,DARKBLUE);//Niên khóa
    for(int i=0;i<=15;i++){
        if(i==0){
        DrawRectangleLines(0,100,55,40,BLACK);//STT
        DrawRectangleLines(55,100,190,40,BLACK);//MSSV
        DrawRectangleLines(245,100,370,40,BLACK);//Họ tên
        DrawRectangleLines(615,100,80,40,BLACK);//Giới tính
        DrawRectangleLines(695,100,195,40,BLACK);//Lớp
        DrawRectangleLines(890,100,390,40,BLACK);//Tên lớp
        DrawRectangleLines(1280,100,220,40,BLACK);//Niên khóa   
        }else if(i>=1){
        DrawRectangleLines(0,100+40*i,55,40,BLACK);//STT
        DrawRectangleLines(55,100+40*i,190,40,BLACK);//MSSV
        DrawRectangleLines(245,100+40*i,370,40,BLACK);//Họ tên
        DrawRectangleLines(615,100+40*i,80,40,BLACK);//Giới tính
        DrawRectangleLines(695,100+40*i,195,40,BLACK);//Lớp
        DrawRectangleLines(890,100+40*i,390,40,BLACK);//Tên lớp
        DrawRectangleLines(1280,100+40*i,220,40,BLACK);//Niên khóa   
        } 
    }
        DrawTextEx(font,"STT",{0,105},30,3,BLACK);
        DrawTextEx(font,"MSSV",{110,105},30,3,BLACK);
        DrawTextEx(font,"Họ và tên",{370,105},30,3,BLACK);
        DrawTextEx(font,"Phái",{630,105},30,3,BLACK);
        DrawTextEx(font,"Lớp",{770,105},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{1045,105},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1325,105},30,3,BLACK);
        for (int place = 0; index < 15 * page && index < dslh.getSoLuong(); index++, place++)
            {
        //     DrawTextEx(font,(char *)dslh[index]->getMaLop().c_str(),Vector2{700, 150 +50* place+10*(-place)}, 28, 1, BLACK);// hiển thị mã lớp, lưu ý: đây chỉ là để tính toán vị trí trước
                DrawTextEx(font,to_string(index+1).c_str(),{10,150+50*place+10*(-place)},30,3,BLACK);//STT
            //  while(sv!=nullptr){
            //     DrawTextEx(font,(char*)sv->sv_data.MASV.c_str(),Vector2{60,150+50*place+10*(-place)},30,1,BLACK);
            //     DrawTextEx(font,(char*)sv->sv_data.HO.c_str(),Vector2{250,150+50*place+10*(-place)},30,3,BLACK);
            //     DrawTextEx(font,(char*)sv->sv_data.TEN.c_str(),Vector2{350,150+50*place+10*(-place)},30,3,BLACK);
            //     DrawTextEx(font,(char*)sv->sv_data.Phai.c_str(),Vector2{635,150+50*place+10*(-place)},30,3,BLACK);
            //     sv = sv->next;
            // }
            }
            
  
           
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
void SauKhiAnVaoNganHangCauHoi(){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(0,0,1500,70,Fade(GRAY,0.3f));
        DrawRectangle(0,70,1500,100,Fade(SKYBLUE,0.5f));
        DrawRectangle(0,650,1500,50,Fade(GOLD,0.6f));
        DrawTextEx(font,"Ngân hàng câu hỏi môn:",{5,20},30,3,Fade(BLUE,0.9f));
        for(int i=0;i<4;i++){
            DrawRectangle(1050+(110*i),15,90,40,BLUE);
            DrawRectangleLines(1050+(110*i),15,90,40,BLACK);
        }
        DrawTextEx(font,"Thêm",{1060,19.5},30,3,BLACK);
        DrawTextEx(font,"Sửa",{1180,19.5},30,3,BLACK);
        DrawTextEx(font,"Xóa",{1290,19.5},30,3,BLACK);
        //DrawTextEx(font,"")

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
            GiaoDienDanhSachLop(dslh);
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



