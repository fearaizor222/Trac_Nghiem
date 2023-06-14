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
    int offset = 0;

    while(!is_close_icon_pressed){

        BeginDrawing();
            ClearBackground(WHITE);

            next.run(is_button_next_pressed);
            prev.run(is_button_prev_pressed);
            if(is_button_next_pressed && page < (dsmh.getLength() - offset) / 7 + 1) page++;
            if(is_button_prev_pressed && page > 1) page--;

            DrawTextEx(font, std::to_string(page).c_str(), {(BotRight().x - 110 + BotRight().x - 220) / 2 - (MeasureTextEx(font, std::to_string(page).c_str(), 30, 3).x / 2) - 200, BotRight().y - 90 + 10}, 30, 3, BLACK);
            DrawTextEx(font, std::to_string((dsmh.getLength() - offset) / 7 + 1).c_str(), {(BotRight().x - 110 + BotRight().x - 220) / 2 - (MeasureTextEx(font, std::to_string((dsmh.getLength() - offset) / 7 + 1).c_str(), 30, 3).x / 2) - 100, BotRight().y - 90 + 10}, 30, 3, BLACK); 
            
            index = 7 * (page - 1);
            offset = 0;

            input_ma_mon.run(global_mouse_pos);
            if(CheckCollisionPointRec(GetMousePosition(), input_ma_mon.box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                page = 1;
            }
            DrawRectangleLinesEx(input_ma_mon.box, 3, BLACK);
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


            for (int place = 0; place < 7 && index < dsmh.getLength(); index++)
            {
                if(input_ma_mon.text.data != ""){
                    if(strstr(dsmh[index].ma_mon_hoc, input_ma_mon.text.data.c_str()) == nullptr &&
                        strstr(standardization(dsmh[index].ten_mon_hoc).c_str(), standardization(input_ma_mon.text.data).c_str()) == nullptr){
                        offset++;
                        continue;
                    }
                }
                // if(index - offset >= 7 * page) place = 1000;

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
                DrawTextEx(font, std::to_string(index + 1 - offset).c_str(), {(5 + 100) / 2 - (MeasureTextEx(font, std::to_string(index + 1 - offset).c_str(), 30, 3).x / 2), 199 + 75 * (place)}, 30, 3, BLACK);
                DrawTextEx(font, dsmh[index].ma_mon_hoc, Vector2{100 + 5, 199 + 75 * (place)}, 30, 3, BLACK);
                DrawTextEx(font, (char *)dsmh[index].ten_mon_hoc.c_str(), Vector2{273 + 5, 199 + 75 * (place)}, 30, 3, BLACK);
                DrawTextEx(font, (char*)output_mark.c_str(), Vector2{(1490 + 1300)/2 - MeasureTextEx(font, (char*)output_mark.c_str(), 30, 3).x/2, 199 + 75 * (place)}, 30, 3, BLACK);

                if(CheckCollisionPointRec(GetMousePosition(), rec)){
                    DrawRectangleLinesEx(rec, 3, GREEN);

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_flag){
                        if(output_mark == "Chưa thi"){
                            press_flag = true;
                            ma_mon_chon_thi = dsmh[index].ma_mon_hoc;
                        }
                    }
                }

                place++;
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
void GiaoDienDanhSachSinhVien(DanhSachLopHoc &dslh, string a);

void GiaoDienDanhSachLop(DanhSachLopHoc &dslh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    int page = 0;
    int index = 0;
    bool press_flag = false;
    bool press_Delete_Button = false;
    bool press_Correction_Button = false;
    bool press_Row_By_Row_Correction_Button = false;
    bool press_Class_To_See_Member_Button = false;
    bool press_Add_Save_Button = false;
    bool press_Delete_Save_Button = false;
    bool press_Are_You_Sure_Button = false;
    bool press_Correction_Save_Button = false;
    bool press_Student_List_Button = false;
    bool press_Menu_Button = false;
    string ma_lop = "";
    string ten_lop = "";
    string nien_khoa = "";
    float cur_page = 0, max_item = 10, line = 160;
    InputBox box_ma_lop(Rectangle{500, 230, 250, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_ten_lop(Rectangle{500, 320, 600, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_nien_khoa(Rectangle{550, 410, 190, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_ma_lop_khi_xoa(Rectangle{695,320,250,50}, BLACK, BLACK, WHITE, font);
    InputBox box_in_danh_sach(Rectangle{10,10,320,40}, BLACK, BLACK, WHITE, font);
    global_mouse_pos = GetMousePosition();
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;


    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(480,705,180,45, Fade(BLUE, 0.2f));
        DrawRectangle(850,705,180,45, Fade(BLUE, 0.2f));
        DrawTextEx(font, "Trang trước",{490,712.5},30,3,BLACK);
        DrawTextEx(font, "Trang sau",{875,712.5},30,3,BLACK);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  
        DrawRectangle(10,10,320,40,WHITE);//Vẽô: Nhập từ khóa
        DrawRectangleLines(10,10,320,40,BLACK);
        DrawRectangle(1350,10,120,40,DARKBLUE);//Ô menu
        DrawRectangleLines(1350,10,120,40,BLACK);
        DrawTextEx(font, "Nhập niên khóa ",{70,15},30,3,GRAY);
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
                DrawRectangleLines(80+(260*i), 100*j, 260, 50, BLACK);
                }else if(i==1){//Tên lớp
                DrawRectangle(80+(260*i),100*j,700,50,BLUE);
                DrawRectangleLines(80+(260*i), 100*j, 700, 50, BLACK);
                }else{//Niên khóa
                DrawRectangle(80+(480*i),100*j,480,50,BLUE);
                DrawRectangleLines(80+(480*i), 100*j, 480, 50, BLACK);
                }
                }
            }else if(j>=3){
            for(int i=0;i<3;i++){
                if(i==0){//mã lớp
                DrawRectangleLines(0,50*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 50*j, 260, 50, BLACK);
                }else if(i==1){//tên lớp
                DrawRectangleLines(80+(260*i), 50*j, 700, 50, BLACK);
                }else{//niên khóa
                DrawRectangleLines(80+(480*i), 50*j, 480, 50, BLACK);  
                }
               
            }
            }
        }
        
        DrawTextEx(font,"STT",{15,110},30,3,BLACK);
        DrawTextEx(font,"Mã lớp",{165,110},30,3,BLACK);
        DrawTextEx(font,"Tên lớp",{640,110},30,3,BLACK);
        DrawTextEx(font,"Niên khóa",{1210,110},30,3,BLACK);
        int count = 0;
        for(int place = cur_page*max_item; place<dslh.getSoLuong() && place<(cur_page+1)*max_item;place++){
              box_in_danh_sach.run(global_mouse_pos);
              

              if(box_in_danh_sach.text.data == ""){
              DrawTextEx(font,to_string(place+1).c_str(),{30,160+50*place-(50*(place/10))*10},30,3,BLACK);//STT
              DrawTextEx(font,(char*)dslh[place]->getMaLop().c_str(),Vector2{90,160+50*place-(50*(place/10))*10},30,3,BLACK);// Mã lớp
              DrawTextEx(font,(char*)dslh[place]->getTenLop().c_str(),Vector2{350,160+50*place-(50*(place/10))*10},30,3,BLACK);//tên lớp
              DrawTextEx(font,(char*)dslh[place]->getNienKhoa().c_str(),Vector2{1200,160+50*place-(50*(place/10))*10},30,3,BLACK);//niên khóa
              }else if(box_in_danh_sach.text.data != ""){
                if(dslh[place]->getNienKhoa() == box_in_danh_sach.text.data){
                    count++;
                    DrawTextEx(font,to_string(count).c_str(),{30,160+50*place-(50*(place/10))*10},30,3,BLACK);//STT
                    DrawTextEx(font,(char*)dslh[place]->getMaLop().c_str(),Vector2{90,160+50*place-(50*(place/10))*10},30,3,BLACK);// Mã lớp
                    DrawTextEx(font,(char*)dslh[place]->getTenLop().c_str(),Vector2{350,160+50*place-(50*(place/10))*10},30,3,BLACK);//tên lớp
                    DrawTextEx(font,(char*)dslh[place]->getNienKhoa().c_str(),Vector2{1200,160+50*place-(50*(place/10))*10},30,3,BLACK);//niên khó    
                
                }
                }
              

                Rectangle rec3 = {0,50*(place+3),1500,50};
                Rectangle rec4 = {310,55,300,40};
                if(CheckCollisionPointRec(GetMousePosition(),rec4)){
                    DrawRectangleLinesEx(rec4, 3, YELLOW);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Correction_Button){
                        press_Correction_Button = true;
                    }
                }
                if(press_Correction_Button){
                    DrawRectangle(700,55,50,40,RED);
                    DrawTextEx(font,"X",{710,60},30,3,YELLOW);
                if(CheckCollisionPointRec(GetMousePosition(),rec3)){
                    DrawRectangleLinesEx(rec3, 3, YELLOW);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Row_By_Row_Correction_Button){
                            press_Row_By_Row_Correction_Button = true;
                            ma_lop = dslh[place]->getMaLop();
                            ten_lop = dslh[place]->getTenLop();
                            nien_khoa = dslh[place]->getNienKhoa();
                        
                    }
                }
                if(press_Row_By_Row_Correction_Button){
                Rectangle main_popup = {350,150, 800, 400};
                Rectangle close_button = {main_popup.x + 750, main_popup.y, 50, 50};
                Rectangle save_button = {700,500,100,40};
                DrawRectangleRec(main_popup, WHITE);
                DrawRectangleRec(close_button, RED);
                DrawRectangleRec(save_button,Fade(YELLOW,0.5f));
                DrawRectangleLinesEx(main_popup, 3, BLACK);
                DrawRectangleLinesEx(close_button, 3, BLACK);
                DrawRectangleLinesEx(save_button, 3, BLACK);
                DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 20, main_popup.y + 90}, 30, 5, BLACK);
                DrawTextEx(font, "Tên lớp:", Vector2{main_popup.x + 20, main_popup.y + 180}, 30, 5, BLACK);
                DrawTextEx(font,"Niên khóa: ",Vector2{main_popup.x + 20, main_popup.y + 270},30,5,BLACK);
                DrawTextEx(font,"Lưu",Vector2{725,505},30,3,BLACK);
                DrawTextEx(font,(char *)ma_lop.c_str(), Vector2{510, 240},30,3,BLACK);
                DrawTextEx(font,(char *)ten_lop.c_str(), Vector2{510, 330},30,3,BLACK);
                DrawTextEx(font,(char *)nien_khoa.c_str(), Vector2{560, 420},30,3,BLACK);

                box_ma_lop.run(global_mouse_pos);
                box_ten_lop.run(global_mouse_pos);
                box_nien_khoa.run(global_mouse_pos);
                if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Correction_Save_Button){
                            press_Correction_Save_Button = true;
                    }
                }
                if(press_Correction_Save_Button){
                    if(box_ma_lop.text.data != ""){
                    dslh[place]->setMaLop(box_ma_lop.text.data);
                    }
                    if(box_ten_lop.text.data != ""){
                    dslh[place]->setTenLop(box_ten_lop.text.data);
                    }
                    if(box_nien_khoa.text.data != ""){
                    dslh[place]->setNienKhoa(box_nien_khoa.text.data);
                    }

                }
                if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                    DrawRectangleRec(close_button, Fade(RED, 0.5f));

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Row_By_Row_Correction_Button = false;
                    }
                }
                }
                if(CheckCollisionPointRec(global_mouse_pos, {700,55,250,40})){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Correction_Button = false;
                    }
                }
                }
                
                if(CheckCollisionPointRec(GetMousePosition(),{80,50*(place+3),260,50})){
                    DrawRectangleLinesEx({80,50*(place+3),260,50},3,RED);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Student_List_Button){
                        press_Student_List_Button = true;
                        ma_lop = dslh[place]->getMaLop();
                    }
                }
            
            if(press_Student_List_Button){
                GiaoDienDanhSachSinhVien(dslh,ma_lop);
                if(CheckCollisionPointRec(GetMousePosition(),{1350,10,120,40})){
                    DrawRectangleLinesEx({1350,10,120,40},3,YELLOW);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Student_List_Button = false;
                    }
                }
            }
        }
        if(CheckCollisionPointRec(GetMousePosition(),{850,705,180,45})){
                DrawRectangleLinesEx({850,705,180,45},3,YELLOW);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !is_button_next_pressed){
                    cur_page++;
                    is_button_next_pressed = true;
                }
              }
        if(CheckCollisionPointRec(GetMousePosition(),{480,705,180,45})){
                DrawRectangleLinesEx({480,705,180,45},3,YELLOW);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !is_button_prev_pressed){
                    cur_page--;
                    if(cur_page<0){
                        cur_page = 0;
                    }
                    is_button_prev_pressed = true;
                }
              }

        Rectangle rec = {10, 55 , 80, 40};
        if(CheckCollisionPointRec(GetMousePosition(), rec)){
                    DrawRectangleLinesEx(rec, 3, YELLOW);

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_flag){
                            press_flag = true;    
                    }
                }
                if(press_flag){
                
                Rectangle main_popup = {350,150, 800, 400};
                Rectangle close_button = {main_popup.x + 750, main_popup.y, 50, 50};
                Rectangle save_button = {700,500,100,40};
                DrawRectangleRec(main_popup, WHITE);
                DrawRectangleRec(close_button, RED);
                DrawRectangleRec(save_button,Fade(YELLOW,0.5f));
                DrawRectangleLinesEx(main_popup, 3, BLACK);
                DrawRectangleLinesEx(close_button, 3, BLACK);
                DrawRectangleLinesEx(save_button, 3, BLACK);
                DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 20, main_popup.y + 90}, 30, 5, BLACK);
                DrawTextEx(font, "Tên lớp:", Vector2{main_popup.x + 20, main_popup.y + 180}, 30, 5, BLACK);
                DrawTextEx(font,"Niên khóa: ",Vector2{main_popup.x + 20, main_popup.y + 270},30,5,BLACK);
                DrawTextEx(font,"Lưu",Vector2{725,505},30,3,BLACK);
                box_ma_lop.run(global_mouse_pos);
                box_ten_lop.run(global_mouse_pos);
                box_nien_khoa.run(global_mouse_pos);
                if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                        DrawRectangleLinesEx(save_button,3,BLUE);
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Add_Save_Button){
                                press_Add_Save_Button = true;
                        }
                }
                if(press_Add_Save_Button){
                    for(int i=0;i<=dslh.getSoLuong();i++){
                        if(dslh[i]->getMaLop()==box_ma_lop.text.data){
                            DrawRectangle(500,300,300,200,RED);
                        }else{ 
                            dslh.insert(new Lop{box_ma_lop.text.data, box_ten_lop.text.data ,box_nien_khoa.text.data});
                            // break;
                        }
                    }
                }
                
                if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                    DrawRectangleRec(close_button, Fade(RED, 0.5f));

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_flag = false;
                    }
                }
            }
            Rectangle rec2 = {160 ,55 ,80 ,40}; 
            if(CheckCollisionPointRec(GetMousePosition(), rec2)){
                    DrawRectangleLinesEx(rec2, 3, YELLOW);

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Button){
                            press_Delete_Button = true;
                    }
                }
             if(press_Delete_Button){
                Rectangle main_popup = {570,240, 375, 200};
                Rectangle close_button = {main_popup.x + 325, main_popup.y, 50, 50};
                Rectangle save_button = {715,395,100,40};
                DrawRectangleRec(main_popup, WHITE);
                DrawRectangleRec(close_button, RED);
                DrawRectangleRec(save_button,Fade(YELLOW,0.5f));
                DrawRectangleLinesEx(main_popup, 3, BLACK);
                DrawRectangleLinesEx(close_button, 3, BLACK);
                DrawRectangleLinesEx(save_button, 3, BLACK);
                DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 10, main_popup.y + 90}, 30, 5, BLACK);
                DrawTextEx(font,"Lưu",Vector2{740,400},30,3,BLACK);
                box_ma_lop_khi_xoa.run(global_mouse_pos);
                if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                        DrawRectangleLinesEx(save_button,3,BLUE);
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Save_Button){
                                press_Delete_Save_Button = true;
                        }
                }
                if(press_Delete_Save_Button){
                    DrawRectangle(600,220,375,200,Fade(BLUE,0.5f));
                    DrawRectangle(660,300,100,40,YELLOW);
                    DrawRectangle(820,300,100,40,YELLOW);
                    DrawTextEx(font,"Có",{695,305},30,3,BLACK);
                    DrawTextEx(font,"Không",{830,305},30,3,BLACK);
        
                    if(CheckCollisionPointRec(GetMousePosition(),{660,300,100,40})){
                        DrawRectangleLinesEx({660,300,100,40},3,RED);
                        
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Are_You_Sure_Button){
                                press_Are_You_Sure_Button = true;
                        }
                    }
                    if(press_Are_You_Sure_Button){
                        int count = 0;
                        dslh.removeClass(box_ma_lop_khi_xoa.text.data);
                        press_Are_You_Sure_Button = false;
                        for(int i=0;i<dslh.getSoLuong();i++){
                            if(dslh[i]->getMaLop()==box_ma_lop_khi_xoa.text.data){
                                dslh.removeClass(box_ma_lop_khi_xoa.text.data);
                                count++;
                                press_Are_You_Sure_Button = false;
                            }
                        }
                        }
                    }
                    if(CheckCollisionPointRec(global_mouse_pos,{820,300,100,40})){
                        DrawRectangleLinesEx({820,300,100,40},3,RED);
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Delete_Save_Button = false;
                    }
                    }
                
                if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                    DrawRectangleRec(close_button, Fade(RED, 0.5f));

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Delete_Button = false;
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
        is_button_prev_pressed = false;
        is_button_next_pressed = false;
    }
}
void in_SinhVien_1_Lop(SVPtr FirstSV, float &cur_page, Font font, string malop, DanhSachLopHoc &dslh);
void GiaoDienDanhSachSinhVien(DanhSachLopHoc &dslh, string a){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    int page = 0;
    int index = 0;
    float line = 145;
    int item_per_page = 0;
    SVPtr sv = dslh[(char*)a.c_str()]->getDSSV()->getFirst();
    bool press_Add_Button = false;
    bool press_Add_Save_Button = false;
    InputBox box_add(Rectangle{10,10,90,40}, BLACK, BLACK, WHITE, font);
    InputBox box_nien_khoa(Rectangle{550, 410, 190, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_MSSV(Rectangle{480,185,210,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Ho_Ten(Rectangle{500,275,550,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Phai(Rectangle{540,365,100,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Password(Rectangle{540,455,150,40}, BLACK, BLACK, WHITE, font);
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    Button prev{{480,750,180,45},"Trang trước",Fade(BLUE,0.2f),BLUE,font};
    Button next{{850,750,180,45},"Trang sau",Fade(BLUE,0.2f),BLUE,font};
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    float cur_page = 0;
    while(!is_close_icon_pressed){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(480,750,180,45,Fade(BLUE,0.2f));
        DrawRectangle(850,750,180,45,Fade(BLUE,0.2f));
        DrawTextEx(font, "Trang trước",{490,755},30,3,BLACK);
        DrawTextEx(font, "Trang sau",{875,755},30,3,BLACK);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));  //vẽ bản màu xám
        DrawRectangle(1350,10,120,40,DARKBLUE);
        DrawRectangleLines(1350,10,120,40,BLACK);
        DrawTextEx(font,"MENU",{1367.5,15},30,3,WHITE);
        DrawRectangle(10,10,90,40,DARKBLUE);
        DrawRectangleLines(10,10,90,40,BLACK);
        DrawTextEx(font,"Thêm",{20,15},30,3,WHITE);
        DrawRectangle(0,100,55,40,DARKBLUE);//STT
        DrawRectangle(55,100,250,40,DARKBLUE);//MSSV
        DrawRectangle(305,100,995,40,DARKBLUE);//Họ tên
        DrawRectangle(1300,100,200,40,DARKBLUE);//Giới tín
    for(int i=0;i<=15;i++){
        if(i==0){
        DrawRectangleLines(0,100,55,40,BLACK);//STT
        DrawRectangleLines(55,100,250,40,BLACK);//MSSV
        DrawRectangleLines(305,100,995,40,BLACK);//Họ tên
        DrawRectangleLines(1300,100,200,40,BLACK);//Giới tính  
        }else if(i>=1){
        DrawRectangleLines(0,100+40*i,55,40,BLACK);//STT
        DrawRectangleLines(55,100+40*i,250,40,BLACK);//MSSV
        DrawRectangleLines(305,100+40*i,995,40,BLACK);//Họ tên
        DrawRectangleLines(1300,100+40*i,200,40,BLACK);//Giới tính
        } 
    }
        DrawTextEx(font,"STT",{0,105},30,3,BLACK);
        DrawTextEx(font,"MSSV",{140,105},30,3,BLACK);
        DrawTextEx(font,"Họ và tên",{760,105},30,3,BLACK);
        DrawTextEx(font,"Phái",{1370,105},30,3,BLACK);
        in_SinhVien_1_Lop(sv, cur_page, font, a, dslh);
                
        if(CheckCollisionPointRec(GetMousePosition(),{10,10,90,40})){
            DrawRectangleLinesEx({10,10,90,40},3,YELLOW);
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Add_Button){
                press_Add_Button = true;
            }
        }
        if(press_Add_Button){
                Rectangle main_popup = {350,150, 800, 400};
                Rectangle close_button = {main_popup.x + 750, main_popup.y, 50, 50};
                Rectangle save_button = {700,500,100,40};
                DrawRectangleRec(main_popup, WHITE);
                DrawRectangleRec(close_button, RED);
                DrawRectangleRec(save_button,Fade(YELLOW,0.5f));
                DrawRectangleLinesEx(close_button, 3,BLACK);
                DrawRectangleLinesEx(save_button, 3,BLACK);
                DrawRectangleLinesEx(main_popup, 3,BLACK);
                DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                DrawTextEx(font, "MSSV:", Vector2{main_popup.x + 20, main_popup.y + 40}, 30, 5, BLACK);
                DrawTextEx(font, "Họ tên:", Vector2{main_popup.x + 20, main_popup.y + 130}, 30, 5, BLACK);
                DrawTextEx(font,"Giới tính: ",Vector2{main_popup.x + 20, main_popup.y + 220},30,5,BLACK);
                DrawTextEx(font,"Ngày sinh: ",Vector2{main_popup.x + 20, main_popup.y +310},30 , 5, BLACK);
                DrawTextEx(font,"Lưu",Vector2{725,505},30,3,BLACK);
                box_MSSV.run(global_mouse_pos);
                box_Ho_Ten.run(global_mouse_pos);
                box_Phai.run(global_mouse_pos);
                box_Password.run(global_mouse_pos);

        if(CheckCollisionPointRec(GetMousePosition(),save_button)){
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Add_Save_Button){
                        press_Add_Save_Button = true;
            }
        }
        if(press_Add_Save_Button){
            string ho, ten;
            DArray<int> question_id;
            ho = box_Ho_Ten.text.data.substr(0,box_Ho_Ten.text.data.find(' '));
            ten = box_Ho_Ten.text.data.substr(box_Ho_Ten.text.data.find(' ')+1, box_Ho_Ten.text.data.size());
            if(box_MSSV.text.data != "" && box_Ho_Ten.text.data != "" && box_Phai.text.data != "" && box_Password.text.data != ""){
            dslh[(char*)a.c_str()]->getDSSV()->insertOrderSV(SinhVien{box_MSSV.text.data, ho, ten, box_Phai.text.data, box_Password.text.data,question_id});
            }
            box_Ho_Ten.text.data = "";
            box_MSSV.text.data = "";
            box_Phai.text.data = "";
            box_Password.text.data = "";
           if(CheckCollisionPointRec(global_mouse_pos,save_button)){
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    press_Add_Save_Button = false;
                }
           }

        }
        if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                DrawRectangleRec(close_button, Fade(RED, 0.5f));

                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Add_Button = false;
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
        is_button_prev_pressed = false;
        is_button_next_pressed = false;
}
}
void in_SinhVien_1_Lop(SVPtr FirstSV, float &cur_page, Font font, string malop, DanhSachLopHoc &dslh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    float line = 145, page = 0;
    int item_per_page = 0;
    int index = 0;
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    for(SVPtr q = FirstSV; q!=nullptr; q = q->next){
            string ho_ten = q->sv_data.HO + " " + q->sv_data.TEN;
                DrawTextEx(font,(char*)q->sv_data.MASV.c_str(),Vector2{60+screenWidth*(page - cur_page),line},30,1,BLACK);
                DrawTextEx(font,(char*)ho_ten.c_str(),Vector2{310+screenWidth*(page - cur_page),line},30,1,BLACK);
                if((index+1)<10){
                    DrawTextEx(font, (char *)to_string(index+1).c_str(),{20+screenWidth*(page - cur_page),line},30,3,BLACK);
                }else{
                    DrawTextEx(font, (char *)to_string(index+1).c_str(),{10+screenWidth*(page - cur_page),line},30,3,BLACK);
                }
                if(q->sv_data.Phai == "Nam"){
                     DrawTextEx(font,(char*)q->sv_data.Phai.c_str(),Vector2{1370+screenWidth*(page - cur_page),line},30,3,BLACK);
                    }else{
                     DrawTextEx(font,(char*)q->sv_data.Phai.c_str(),Vector2{1380+screenWidth*(page - cur_page),line},30,3,BLACK);
                    }
                    line+=40;
                    item_per_page++;
                    if(item_per_page==15){
                        page++;
                        line = 145;
                        item_per_page = 0;
                    }      
                    index++;
    }
        if(IsKeyPressed(KEY_LEFT)){
        cur_page--;
        if(cur_page<0){
            cur_page = 0;
        }
}
    if(IsKeyPressed(KEY_RIGHT)){
        cur_page++;
    }
    if(CheckCollisionPointRec(GetMousePosition(),{850,750,180,45})){
        DrawRectangleLinesEx({850,750,180,45}, 3, YELLOW);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !is_button_next_pressed){
            cur_page++;
            is_button_next_pressed = true;
        }
    }
    if(CheckCollisionPointRec(GetMousePosition(),{480,750,180,45})){
        DrawRectangleLinesEx({480,750,180,45}, 3, YELLOW);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !is_button_prev_pressed){
            cur_page--;
            if(cur_page<0){
                cur_page = 0;
            }
            is_button_prev_pressed = true;
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

//     current_scene = scene_stack.pop();
//     while (current_scene != Exit || is_close_icon_pressed)
//     {
//         switch (current_scene)
//         {
//         case Login:
//             LoginScene(dslh, sv);
//             // std::cout<<(sv == nullptr)<<std::endl;
//             current_scene = scene_stack.pop();
//             break;

//         case Main_SV:
//             MainSceneSV(sv, dsmh, dsch);
//             current_scene = scene_stack.pop();
//             break;

//         case Main_GV:
//             GiaoDienDanhSachLop(dslh);
//             current_scene = scene_stack.pop();
//             break;

//         case Testing:
//             // TestingScene(dsch);
//             current_scene = scene_stack.pop();
//             break;

//         case Exit:
//             goto exit_tag;
//         }
//     }
//    exit_tag:
string a;
    GiaoDienDanhSachLop(dslh);
     GiaoDienDanhSachSinhVien(dslh,a);
   Deinitialize();
   return 0;

}