#include "../header/raylib.h"
#include "../header/UserInterface.h"
#include "../header/Helper.h"

void GiaoDienDanhSachSinhVien(DanhSachLopHoc &dslh, string a);
void GiaoDienDanhSachLop(DanhSachLopHoc &dslh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    int page = 1;
    int index = 0;
    //  int *nk = new int[MAX_DSL];
    DArray<bool> press_Another_Row_By_Row_Correction_Button;
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
    float cur_page = 0, max_item = 10;
    InputBox box_ma_lop(Rectangle{500, 230, 250, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_ten_lop(Rectangle{500, 320, 600, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_nien_khoa(Rectangle{550, 410, 190, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_ma_lop_khi_xoa(Rectangle{695, 320, 250, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_in_danh_sach(Rectangle{10, 10, 320, 40}, BLACK, BLACK, WHITE, font);
    Button next{{850, 705, 180, 45}, "Next", WHITE, BLUE, font};
    Button prev{{480, 705, 180, 45}, "Prev", WHITE, BLUE, font};
    int offset = 0;
    global_mouse_pos = GetMousePosition();
    SetWindowPosition(GetMonitorWidth(0) / 2 - screenWidth / 2, GetMonitorHeight(0) / 2 - screenHeight / 2);
    SetWindowSize(screenWidth, screenHeight);
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;

    while (!is_close_icon_pressed)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // DrawRectangle(480,705,180,45, Fade(BLUE, 0.2f));
        // DrawRectangle(850,705,180,45, Fade(BLUE, 0.2f));
        // DrawTextEx(font, "Trang trước",{490,712.5},30,3,BLACK);
        // DrawTextEx(font, "Trang sau",{875,712.5},30,3,BLACK);
        DrawRectangle(0, 0, 1500, 100, Fade(GRAY, 0.5f));
        DrawRectangle(10, 10, 320, 40, WHITE); // Vẽô: Nhập từ khóa
        DrawRectangleLines(10, 10, 320, 40, BLACK);
        DrawRectangle(1350, 10, 120, 40, DARKBLUE); // Ô menu
        DrawRectangleLines(1350, 10, 120, 40, BLACK);
        DrawTextEx(font, "Nhập niên khóa ", {70, 15}, 30, 3, GRAY);
        DrawTextEx(font, "MENU", {1367.5, 15}, 30, 3, WHITE);
        for (int i = 0; i < 3; i++)
        {
            if (i != 2)
            {
                DrawRectangle(10 + (150 * i), 55, 80, 40, DARKBLUE); // ô thêm, xóa
                DrawRectangleLines(10 + (150 * i), 55, 80, 40, BLACK);
            }
            else if (i == 2)
            {
                DrawRectangle(10 + (150 * i), 55, 300, 40, DARKBLUE); // ô hiệu chỉnh
                DrawRectangleLines(10 + (150 * i), 55, 300, 40, BLACK);
            }
        }
        DrawTextEx(font, "Thêm", {13.5, 60}, 30, 3, WHITE);
        DrawTextEx(font, "Xóa", {174.5, 60}, 30, 3, WHITE);
        DrawTextEx(font, "Hiệu chỉnh thông tin", {325, 60}, 30, 3, WHITE);
        for (int j = 1; j < 13; j++)
        {
            if (j == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    DrawRectangle(0, 100, 80, 50, BLUE); // ô STT
                    DrawRectangleLines(0, 100 * j, 80, 50, BLACK);
                    if (i == 0)
                    { // mã lớp
                        DrawRectangle(80 + (260 * i), 100 * j, 260, 50, BLUE);
                        DrawRectangleLines(80 + (260 * i), 100 * j, 260, 50, BLACK);
                    }
                    else if (i == 1)
                    { // Tên lớp
                        DrawRectangle(80 + (260 * i), 100 * j, 700, 50, BLUE);
                        DrawRectangleLines(80 + (260 * i), 100 * j, 700, 50, BLACK);
                    }
                    else
                    { // Niên khóa
                        DrawRectangle(80 + (480 * i), 100 * j, 480, 50, BLUE);
                        DrawRectangleLines(80 + (480 * i), 100 * j, 480, 50, BLACK);
                    }
                }
            }
            else if (j >= 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (i == 0)
                    { // mã lớp
                        DrawRectangleLines(0, 50 * j, 80, 50, BLACK);
                        DrawRectangleLines(80 + (480 * i), 50 * j, 260, 50, BLACK);
                    }
                    else if (i == 1)
                    { // tên lớp
                        DrawRectangleLines(80 + (260 * i), 50 * j, 700, 50, BLACK);
                    }
                    else
                    { // niên khóa
                        DrawRectangleLines(80 + (480 * i), 50 * j, 480, 50, BLACK);
                    }
                }
            }
        }

        DrawTextEx(font, "STT", {15, 110}, 30, 3, BLACK);
        DrawTextEx(font, "Mã lớp", {165, 110}, 30, 3, BLACK);
        DrawTextEx(font, "Tên lớp", {640, 110}, 30, 3, BLACK);
        DrawTextEx(font, "Niên khóa", {1210, 110}, 30, 3, BLACK);
        int count = 0;
        box_in_danh_sach.run(global_mouse_pos);
        next.run(is_button_next_pressed);
        prev.run(is_button_prev_pressed);
        if (is_button_next_pressed && page < (dslh.getSoLuong() - offset) / 10 + 1)
            page++;
        if (is_button_prev_pressed && page > 1)
            page--;
        index = 10 * (page - 1);
        offset = 0;
        if (CheckCollisionPointRec(GetMousePosition(), box_in_danh_sach.box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            page = 1;
        }
        for (int place = 0; index < dslh.getSoLuong(); index++)
        {

            if (box_in_danh_sach.text.data != "")
            {
                if (strstr((char *)dslh[index]->getNienKhoa().c_str(), (char *)box_in_danh_sach.text.data.c_str()) == nullptr)
                {
                    offset++;
                    continue;
                }
            }

            if (place > 9)
                place = 100000;

            DrawTextEx(font, to_string(index + 1).c_str(), {30, 160 + 50 * place}, 30, 3, BLACK);                        // STT
            DrawTextEx(font, (char *)dslh[index]->getMaLop().c_str(), Vector2{90, 160 + 50 * place}, 30, 3, BLACK);      // Mã lớp
            DrawTextEx(font, (char *)dslh[index]->getTenLop().c_str(), Vector2{350, 160 + 50 * place}, 30, 3, BLACK);    // tên lớp
            DrawTextEx(font, (char *)dslh[index]->getNienKhoa().c_str(), Vector2{1200, 160 + 50 * place}, 30, 3, BLACK); // niên khóa

            if (CheckCollisionPointRec(GetMousePosition(), {80, 50 * (place + 3), 260, 50}))
            {
                DrawRectangleLinesEx({80, 50 * (place + 3), 260, 50}, 3, RED);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Student_List_Button)
                {
                    press_Student_List_Button = true;
                    ma_lop = dslh[place]->getMaLop();
                }
            }

            if (press_Student_List_Button)
            {
                GiaoDienDanhSachSinhVien(dslh, ma_lop);
                if (CheckCollisionPointRec(GetMousePosition(), {1350, 10, 120, 40}))
                {
                    DrawRectangleLinesEx({1350, 10, 120, 40}, 3, YELLOW);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        press_Student_List_Button = false;
                    }
                }
            }
            place++;
        }
        Rectangle rec4 = {310, 55, 300, 40};

        if (CheckCollisionPointRec(GetMousePosition(), rec4))
        {
            DrawRectangleLinesEx(rec4, 3, YELLOW);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Correction_Button)
            {
                press_Correction_Button = true;
            }
        }
        if (press_Correction_Button)
        {
            DrawRectangle(700, 55, 50, 40, RED);
            DrawTextEx(font, "X", {710, 60}, 30, 3, YELLOW);
            for (int place = 0, index = 0; index < dslh.getSoLuong(); index++)
            {
                if (place > 9) place = 100000;
                Rectangle rec3 = {0, 50 * (place + 3), 80, 50};
                press_Another_Row_By_Row_Correction_Button.push_back(false);
                if (CheckCollisionPointRec(GetMousePosition(), rec3))
                {
                    DrawRectangleLinesEx(rec3, 3, YELLOW);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Another_Row_By_Row_Correction_Button[index])
                    {
                        press_Another_Row_By_Row_Correction_Button[index] = true;
                        ma_lop = dslh[place]->getMaLop();
                        ten_lop = dslh[place]->getTenLop();
                        nien_khoa = dslh[place]->getNienKhoa();
                    }
                }
                if (press_Another_Row_By_Row_Correction_Button[index])
                {
                    Rectangle main_popup = {350, 150, 800, 400};
                    Rectangle close_button = {main_popup.x + 750, main_popup.y, 50, 50};
                    Rectangle save_button = {700, 500, 100, 40};
                    DrawRectangleRec(main_popup, WHITE);
                    DrawRectangleRec(close_button, RED);
                    DrawRectangleRec(save_button, Fade(YELLOW, 0.5f));
                    DrawRectangleLinesEx(main_popup, 3, BLACK);
                    DrawRectangleLinesEx(close_button, 3, BLACK);
                    DrawRectangleLinesEx(save_button, 3, BLACK);
                    DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
                    DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 20, main_popup.y + 90}, 30, 5, BLACK);
                    DrawTextEx(font, "Tên lớp:", Vector2{main_popup.x + 20, main_popup.y + 180}, 30, 5, BLACK);
                    DrawTextEx(font, "Niên khóa: ", Vector2{main_popup.x + 20, main_popup.y + 270}, 30, 5, BLACK);
                    DrawTextEx(font, "Lưu", Vector2{725, 505}, 30, 3, BLACK);
                    if(!box_ma_lop.clicked && box_ma_lop.text.data == "")DrawTextEx(font, (char *)ma_lop.c_str(), Vector2{510, 240}, 30, 3, BLACK);
                    if(!box_ten_lop.clicked && box_ten_lop.text.data == "")DrawTextEx(font, (char *)ten_lop.c_str(), Vector2{510, 330}, 30, 3, BLACK);
                    if(!box_nien_khoa.clicked && box_nien_khoa.text.data == "")DrawTextEx(font, (char *)nien_khoa.c_str(), Vector2{560, 420}, 30, 3, BLACK);

                    box_ma_lop.run(global_mouse_pos);
                    box_ten_lop.run(global_mouse_pos);
                    box_nien_khoa.run(global_mouse_pos);
                    if (CheckCollisionPointRec(GetMousePosition(), save_button))
                    {
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Correction_Save_Button)
                        {
                            press_Correction_Save_Button = true;
                        }
                    }
                    if (press_Correction_Save_Button)
                    {
                        if (box_ma_lop.text.data != "")
                        {
                            if(dslh.searchClass(box_ma_lop.text.data) == -1)
                            {
                                dslh[place]->setMaLop(box_ma_lop.text.data);
                                ma_lop = dslh[place]->getMaLop();
                            }
                            box_ma_lop.text.data = "";
                        }
                        if (box_ten_lop.text.data != "")
                        {
                            dslh[place]->setTenLop(box_ten_lop.text.data);
                            ten_lop = dslh[place]->getTenLop();
                            box_ten_lop.text.data = "";
                        }
                        if (box_nien_khoa.text.data != "")
                        {
                            dslh[place]->setNienKhoa(box_nien_khoa.text.data);
                            nien_khoa = dslh[place]->getNienKhoa();
                            box_nien_khoa.text.data = "";
                        }
                        if (CheckCollisionPointRec(global_mouse_pos, save_button))
                        {
                            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                            {
                                press_Correction_Save_Button = false;
                            }
                        }
                    }
                    if (CheckCollisionPointRec(global_mouse_pos, close_button))
                    {
                        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {
                            press_Another_Row_By_Row_Correction_Button[index] = false;
                        }
                    }
                }

                place++;
            }
            if (CheckCollisionPointRec(global_mouse_pos, {700, 55, 50, 40}))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    press_Correction_Button = false;
                }
            }
        }

        Rectangle rec = {10, 55, 80, 40};
        if (CheckCollisionPointRec(GetMousePosition(), rec))
        {
            DrawRectangleLinesEx(rec, 3, YELLOW);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_flag)
            {
                press_flag = true;
            }
        }
        if (press_flag)
        {

            Rectangle main_popup = {350, 150, 800, 400};
            Rectangle close_button = {main_popup.x + 750, main_popup.y, 50, 50};
            Rectangle save_button = {700, 500, 100, 40};
            DrawRectangleRec(main_popup, WHITE);
            DrawRectangleRec(close_button, RED);
            DrawRectangleRec(save_button, Fade(YELLOW, 0.5f));
            DrawRectangleLinesEx(main_popup, 3, BLACK);
            DrawRectangleLinesEx(close_button, 3, BLACK);
            DrawRectangleLinesEx(save_button, 3, BLACK);
            DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
            DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 20, main_popup.y + 90}, 30, 5, BLACK);
            DrawTextEx(font, "Tên lớp:", Vector2{main_popup.x + 20, main_popup.y + 180}, 30, 5, BLACK);
            DrawTextEx(font, "Niên khóa: ", Vector2{main_popup.x + 20, main_popup.y + 270}, 30, 5, BLACK);
            DrawTextEx(font, "Lưu", Vector2{725, 505}, 30, 3, BLACK);
            box_ma_lop.run(global_mouse_pos);
            box_ten_lop.run(global_mouse_pos);
            box_nien_khoa.run(global_mouse_pos);
            if (CheckCollisionPointRec(GetMousePosition(), save_button))
            {
                DrawRectangleLinesEx(save_button, 3, BLUE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Add_Save_Button)
                {
                    press_Add_Save_Button = true;
                }
            }
            if (press_Add_Save_Button)
            {
                if (dslh.searchClass(box_ma_lop.text.data) < 0)
                {
                    dslh.insert(new Lop{box_ma_lop.text.data, box_ten_lop.text.data, box_nien_khoa.text.data});
                }
                box_ma_lop.text.data = "";
                box_ten_lop.text.data = "";
                box_nien_khoa.text.data = "";
                press_Add_Save_Button = false;
                press_flag = false;
            }

            if (CheckCollisionPointRec(global_mouse_pos, close_button))
            {
                DrawRectangleRec(close_button, Fade(RED, 0.5f));
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    press_flag = false;
                }
            }
        }
        Rectangle rec2 = {160, 55, 80, 40};
        if (CheckCollisionPointRec(GetMousePosition(), rec2))
        {
            DrawRectangleLinesEx(rec2, 3, YELLOW);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Button)
            {
                press_Delete_Button = true;
            }
        }
        if (press_Delete_Button)
        {
            Rectangle main_popup = {570, 240, 375, 200};
            Rectangle close_button = {main_popup.x + 325, main_popup.y, 50, 50};
            Rectangle save_button = {715, 395, 100, 40};
            DrawRectangleRec(main_popup, WHITE);
            DrawRectangleRec(close_button, RED);
            DrawRectangleRec(save_button, Fade(YELLOW, 0.5f));
            DrawRectangleLinesEx(main_popup, 3, BLACK);
            DrawRectangleLinesEx(close_button, 3, BLACK);
            DrawRectangleLinesEx(save_button, 3, BLACK);
            DrawTextEx(font, "X", {close_button.x + 15, close_button.y + 10}, 30, 5, WHITE);
            DrawTextEx(font, "Mã lớp:", Vector2{main_popup.x + 10, main_popup.y + 90}, 30, 5, BLACK);
            DrawTextEx(font, "Lưu", Vector2{740, 400}, 30, 3, BLACK);
            box_ma_lop_khi_xoa.run(global_mouse_pos);
            if (CheckCollisionPointRec(GetMousePosition(), save_button))
            {
                DrawRectangleLinesEx(save_button, 3, BLUE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Save_Button)
                {
                    press_Delete_Save_Button = true;
                }
            }
            if (press_Delete_Save_Button)
            {
                DrawRectangle(600, 220, 375, 200, Fade(BLUE, 0.5f));
                DrawRectangle(660, 300, 100, 40, YELLOW);
                DrawRectangle(820, 300, 100, 40, YELLOW);
                DrawTextEx(font, "Bạn có chắc chắn không?", {615, 260}, 30, 3, BLACK);
                DrawTextEx(font, "Có", {695, 305}, 30, 3, BLACK);
                DrawTextEx(font, "Không", {830, 305}, 30, 3, BLACK);

                if (CheckCollisionPointRec(GetMousePosition(), {660, 300, 100, 40}))
                {

                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Are_You_Sure_Button)
                    {
                        press_Are_You_Sure_Button = true;
                    }
                }
                if (press_Are_You_Sure_Button)
                {
                    int count = 0;
                    dslh.removeClass(box_ma_lop_khi_xoa.text.data);
                    press_Are_You_Sure_Button = false;
                }
            }
            if (CheckCollisionPointRec(global_mouse_pos, {820, 300, 100, 40}))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    press_Delete_Save_Button = false;
                }
            }

            if (CheckCollisionPointRec(global_mouse_pos, close_button))
            {
                DrawRectangleRec(close_button, Fade(RED, 0.5f));

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    press_Delete_Button = false;
                }
            }
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            is_close_icon_pressed = true;
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
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
    bool press_Delete_Button = false;
    bool press_Delete_Save_Button = false;
    bool press_Are_You_Sure_Button = false;
    bool press_Back_Button = false;
    InputBox box_add(Rectangle{10,10,90,40}, BLACK, BLACK, WHITE, font);
    InputBox box_nien_khoa(Rectangle{550, 410, 190, 50}, BLACK, BLACK, WHITE, font);
    InputBox box_MSSV(Rectangle{480,185,210,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Ho_Ten(Rectangle{500,275,550,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Phai(Rectangle{540,365,100,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Password(Rectangle{540,455,150,40}, BLACK, BLACK, WHITE, font);
    InputBox box_MSSV_Xoa(Rectangle{695,320,240,50}, BLACK, BLACK, WHITE, font);
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
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
        DrawTextEx(font,"BACK",{1372.5,15},30,3,WHITE);
        DrawRectangle(10,10,90,40,DARKBLUE);
        DrawRectangleLines(10,10,90,40,BLACK);
        DrawTextEx(font,"Thêm",{20,15},30,3,WHITE);
        DrawRectangle(140,10,90,40,DARKBLUE);
        DrawRectangleLines(140,10,90,40,BLACK);
        DrawTextEx(font,"Xóa",{160,15},30,3,WHITE);
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
                DrawTextEx(font,"Mật khẩu: ",Vector2{main_popup.x + 20, main_popup.y +310},30 , 5, BLACK);
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
            int count = 0;
            for(SVPtr ex = sv; ex != NULL; ex = ex->next){
                if(ex->sv_data.MASV==box_MSSV.text.data){
                    count++;
                }
            }
            ho = box_Ho_Ten.text.data.substr(0,box_Ho_Ten.text.data.find(' '));
            ten = box_Ho_Ten.text.data.substr(box_Ho_Ten.text.data.find(' ')+1, box_Ho_Ten.text.data.size());
            if(box_MSSV.text.data != "" && box_Ho_Ten.text.data != "" && box_Phai.text.data != "" && box_Password.text.data != ""){
                if(count==0){
                    dslh[(char*)a.c_str()]->getDSSV()->insertOrderSV(SinhVien{box_MSSV.text.data, ho, ten, box_Phai.text.data, box_Password.text.data,question_id});
                }
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
        if(CheckCollisionPointRec(GetMousePosition(),{140,10,90,40})){
            DrawRectangleLinesEx({140,10,90,40}, 3, YELLOW);
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
                DrawTextEx(font, "MSSV:", Vector2{main_popup.x + 10, main_popup.y + 90}, 30, 5, BLACK);
                DrawTextEx(font,"Lưu",Vector2{740,400},30,3,BLACK);
                box_MSSV_Xoa.run(global_mouse_pos);
                if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Save_Button){
                        press_Delete_Save_Button = true;
                    }
                }
                if(press_Delete_Save_Button){
                    DrawRectangle(600,220,375,200,SKYBLUE);
                    DrawRectangleLines(600,220,375,200,BLACK);
                    DrawRectangle(660,300,100,40,YELLOW);
                    DrawRectangle(820,300,100,40,YELLOW);
                    DrawTextEx(font,"Bạn có chắc chắn không?",{615,260},30,3,BLACK);
                    DrawTextEx(font,"Có",{695,305},30,3,BLACK);
                    DrawTextEx(font,"Không",{830,305},30,3,BLACK);
                    if(CheckCollisionPointRec(GetMousePosition(),{660,300,100,40})){
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Are_You_Sure_Button){
                            press_Are_You_Sure_Button = true;
                        }
                    }
                    if(press_Are_You_Sure_Button){
                        dslh[(char*)a.c_str()]->getDSSV()->deleteSV(box_MSSV_Xoa.text.data);
                        box_MSSV_Xoa.text.data = "";
                        press_Delete_Save_Button = false;
                        press_Are_You_Sure_Button = false;
                    }
                    if(CheckCollisionPointRec(global_mouse_pos,{820,300,100,40})){
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                            press_Delete_Save_Button = false;
                        }
                    }
                }
                if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Delete_Button = false;
                    }
                }
        }
        if(CheckCollisionPointRec(GetMousePosition(),{1350,10,120,40})){
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Back_Button){
                press_Back_Button = true;
            }
        }
        if(press_Back_Button){
            GiaoDienDanhSachLop(dslh);
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
void inDanhSachMon(DanhSachMonHoc &dsmh, float &cur_page, int max_item, bool is_button_next_pressed, bool is_button_prev_pressed){
    for(int place = cur_page*max_item;place<dsmh.getLength() && place<(cur_page+1)*max_item; place++){
              DrawTextEx(font,to_string(place+1).c_str(),{30,160+50*place-500*(place/10)},30,3,BLACK);
              DrawTextEx(font,dsmh[place].ma_mon_hoc,Vector2{90,160+50*place-500*(place/10)},30,3,BLACK);
              DrawTextEx(font,(char*)dsmh[place].ten_mon_hoc.c_str(),Vector2{350,160+50*place-500*(place/10)},30,3,BLACK);

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
}
void GiaoDienDanhSachMon (DanhSachMonHoc &dsmh){
    const int screenWidth = 1500;
    const int screenHeight = 800;
    float cur_page = 0;
    int max_item = 10;              
    string ma_mon = "";
    string ten_mon = "";
    InputBox box_Ma_Mon(Rectangle{500,275,250,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Ten_Mon(Rectangle{540,380,550,40}, BLACK, BLACK, WHITE, font);
    InputBox box_Ma_Mon_Xoa(Rectangle{705,320,230,50}, BLACK, BLACK, WHITE, font);
    Button next{{850, 705, 180, 45}, "Next", WHITE, BLUE, font};
    Button prev{{480, 705, 180, 45}, "Prev", WHITE, BLUE, font};
    global_mouse_pos = GetMousePosition();
    bool is_button_next_pressed = false;
    bool is_button_prev_pressed = false;
    bool press_Add_Button = false;
    bool press_Add_Save_Button = false;
    bool press_Delete_Button = false;
    bool press_Delete_Save_Button = false;
    bool press_Are_You_Sure_Button = false;
    bool press_Correction_Button = false;
    bool press_Correction_Save_Button = false;
    DArray<bool> press_Row_By_Row_Correction_Button;
    SetWindowPosition(GetMonitorWidth(0)/2 - screenWidth/2, GetMonitorHeight(0)/2 - screenHeight/2);
    SetWindowSize(screenWidth, screenHeight);
    while(!is_close_icon_pressed){
        BeginDrawing();
        ClearBackground(WHITE);


        DrawRectangle(480,705,180,45, Fade(BLUE, 0.2f));
        DrawRectangle(850,705,180,45, Fade(BLUE, 0.2f));
        DrawTextEx(font, "Trang trước",{490,712.5},30,3,BLACK);
        DrawTextEx(font, "Trang sau",{875,712.5},30,3,BLACK);
        DrawRectangle(0,0,1500,100,Fade(GRAY, 0.5f));
        DrawRectangle(1350,10,120,40,DARKBLUE);
        DrawRectangleLines(1350,10,120,40,BLACK);
        DrawTextEx(font,"BACK",{1372.5,15},30,3,WHITE);
  
        for(int i=0;i<3;i++){
            if(i!=2){
                DrawRectangle(10+(150*i),10,80,40,DARKBLUE);//ô thêm, xóa
                DrawRectangleLines(10+(150*i),10,80,40,BLACK);
            }else if(i==2){
                DrawRectangle(10+(150*i),10,300,40,DARKBLUE);// ô hiệu chỉnh
                DrawRectangleLines(10+(150*i),10,300,40,BLACK);
            }       
        }
        DrawTextEx(font,"Thêm",{13.5,15},30,3,WHITE);
        DrawTextEx(font,"Xóa",{174.5,15},30,3,WHITE);
        DrawTextEx(font,"Hiệu chỉnh thông tin",{325,15},30,3,WHITE);
        for(int j=1;j<13;j++){
            if(j==1){
                for(int i=0;i<3;i++){
                  DrawRectangle(0,100,80,50,BLUE);
                  DrawRectangleLines(0,100*j,80,50,BLACK);
                if(i==0){
                DrawRectangle(80+(260*i),100*j,260,50,BLUE);
                DrawRectangleLines(80+(260*i), 100*j, 260, 50, BLACK);
                }else if(i==1){
                DrawRectangle(80+(260*i),100*j,1160,50,BLUE);
                DrawRectangleLines(80+(260*i), 100*j, 1160, 50, BLACK);
                }
                }
            }else if(j>=3){
            for(int i=0;i<3;i++){
                if(i==0){
                DrawRectangleLines(0,50*j,80,50,BLACK);
                DrawRectangleLines(80+(480*i), 50*j, 260, 50, BLACK);
                }else if(i==1){
                DrawRectangleLines(80+(260*i), 50*j, 1160, 50, BLACK);
                }
               
            }
            }
        }
        DrawTextEx(font,"STT",{15,110},30,3,BLACK);
        DrawTextEx(font,"Mã môn",{155,110},30,3,BLACK);
        DrawTextEx(font,"Tên môn học",{840,110},30,3,BLACK);
        inDanhSachMon(dsmh, cur_page, max_item, is_button_next_pressed, is_button_prev_pressed);
        if(CheckCollisionPointRec(GetMousePosition(),{10,10,80,40})){
            DrawRectangleLinesEx({10,10,80,40},3,YELLOW);
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
                DrawTextEx(font, "Mã môn:", Vector2{main_popup.x + 20, main_popup.y + 130}, 30, 5, BLACK);
                DrawTextEx(font, "Tên môn:", Vector2{main_popup.x + 20, main_popup.y + 240}, 30, 5, BLACK);
                DrawTextEx(font,"Lưu",Vector2{725,505},30,3,BLACK);
                box_Ma_Mon.run(global_mouse_pos);
                box_Ten_Mon.run(global_mouse_pos);
                if(CheckCollisionPointRec(GetMousePosition(), save_button)){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Add_Save_Button){
                        press_Add_Save_Button = true;
                    }
                }
                if(press_Add_Save_Button){
                   if(box_Ma_Mon.text.data != "" && box_Ten_Mon.text.data != ""){
                    if(dsmh.search((char*)box_Ma_Mon.text.data.c_str())<0){
                    dsmh.insert(MonHoc{(char*)box_Ma_Mon.text.data.c_str(), box_Ten_Mon.text.data});
                    }
                   }
                    box_Ma_Mon.text.data = box_Ten_Mon.text.data = "";
                    press_Add_Save_Button = false;
                    
                }
                if(CheckCollisionPointRec(global_mouse_pos,close_button)){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Add_Button = false;
                    }
                }
        }
        if(CheckCollisionPointRec(GetMousePosition(),{160,10,80,40})){
            DrawRectangleLinesEx({160,10,80,40}, 3, YELLOW);
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
            DrawTextEx(font, "Mã môn:", Vector2{main_popup.x + 10, main_popup.y + 90}, 30, 5, BLACK);
            DrawTextEx(font,"Lưu",Vector2{740,400},30,3,BLACK);
            box_Ma_Mon_Xoa.run(global_mouse_pos);
            if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Delete_Save_Button){
                    press_Delete_Save_Button = true;
                }
            }
            if(press_Delete_Save_Button){
                DrawRectangle(600,220,375,200,SKYBLUE);
                DrawRectangleLines(600,220,375,200,BLACK);
                DrawRectangle(660,300,100,40,YELLOW);
                DrawRectangle(820,300,100,40,YELLOW);
                DrawTextEx(font,"Bạn có chắc chắn không?",{615,260},30,3,BLACK);
                DrawTextEx(font,"Có",{695,305},30,3,BLACK);
                DrawTextEx(font,"Không",{830,305},30,3,BLACK);
                if(CheckCollisionPointRec(global_mouse_pos,{660,300,100,40})){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Are_You_Sure_Button){
                        press_Are_You_Sure_Button = true;
                    }
                }
                if(press_Are_You_Sure_Button){
                    dsmh.remove((char *)box_Ma_Mon_Xoa.text.data.c_str());
                    box_Ma_Mon_Xoa.text.data = "";
                    press_Delete_Save_Button = false;
                    press_Are_You_Sure_Button = false;
                }
                if(CheckCollisionPointRec(global_mouse_pos,{820,300,100,40})){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        press_Delete_Save_Button = false;
                    }
                }
            }
            if(CheckCollisionPointRec(global_mouse_pos,{close_button})){
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    press_Delete_Button = false;
                }
            }
        }
        for(int place = cur_page*max_item; place<dsmh.getLength() && place<(cur_page+1)*max_item; place++){
            press_Row_By_Row_Correction_Button.push_back(false);
        }
         for(int place = cur_page*max_item; place<dsmh.getLength() && place<(cur_page+1)*max_item;place++){
                
                Rectangle rec3 = {0,50*(place+3)-(50*(place/10))*10,80,50};
                Rectangle rec4 = {310,10,300,40};
                if(CheckCollisionPointRec(GetMousePosition(),rec4)){
                    DrawRectangleLinesEx(rec4, 3, YELLOW);
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Correction_Button){
                        press_Correction_Button = true;
                    }
                }
                if(press_Correction_Button){
                    DrawRectangle(700,55,40,40,RED);
                    DrawTextEx(font,"X",{710,60},30,3,YELLOW);
                    if(CheckCollisionPointRec(GetMousePosition(),rec3)){
                        DrawRectangleLinesEx(rec3, 3, RED);
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !press_Row_By_Row_Correction_Button[place]){
                            press_Row_By_Row_Correction_Button[place] = true;
                            ma_mon = dsmh[place].ma_mon_hoc;
                            ten_mon = dsmh[place].ten_mon_hoc;
                        }
                    }
                    if(press_Row_By_Row_Correction_Button[place]){

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
                        DrawTextEx(font, "Mã môn:", Vector2{main_popup.x + 20, main_popup.y + 130}, 30, 5, BLACK);
                        DrawTextEx(font, "Tên môn:", Vector2{main_popup.x + 20, main_popup.y + 240}, 30, 5, BLACK);
                        DrawTextEx(font,"Lưu",Vector2{725,505},30,3,BLACK);
                        DrawTextEx(font,(char*)ma_mon.c_str(),{box_Ma_Mon.box.x+10, box_Ma_Mon.box.y+5}, 30, 5, BLACK);
                        DrawTextEx(font,(char*)ten_mon.c_str(),{550, box_Ten_Mon.box.y+5}, 30, 5, BLACK);
                        box_Ma_Mon.run(global_mouse_pos);
                        box_Ten_Mon.run(global_mouse_pos);
                        if(CheckCollisionPointRec(GetMousePosition(),save_button)){
                            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON && !press_Correction_Save_Button)){
                                press_Correction_Save_Button = true;
                            }
                        }
                        if(press_Correction_Save_Button){
                            if(box_Ma_Mon.text.data != ""){
                                strcpy(dsmh[place].ma_mon_hoc, (char *)box_Ma_Mon.text.data.c_str());
                            }
                            if(box_Ten_Mon.text.data != ""){
                                dsmh[place].ten_mon_hoc = box_Ten_Mon.text.data;
                            }
                            box_Ma_Mon.text.data = box_Ten_Mon.text.data = "";
                            press_Correction_Save_Button = false;
                        }
                        if(CheckCollisionPointRec(global_mouse_pos, close_button)){
                            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                                press_Row_By_Row_Correction_Button[place] = false;
                            }
                        }
                    }
                    if(CheckCollisionPointRec(GetMousePosition(),{700,55,40,40})){
                        DrawRectangleLinesEx({700,55,40,40},3,YELLOW);
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                            press_Correction_Button = false;
                        }
                    }
                }
    }
        EndDrawing();
        if(WindowShouldClose()){
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
    std::string testing_subject;
    std::string time;
    std::string number_of_questions;

//     current_scene = scene_stack.pop();
//     while (current_scene != Exit || is_close_icon_pressed)
//     {
//         switch (current_scene)
//         {
//         case Login:
//             LoginScene(dslh, sv);
//             current_scene = scene_stack.pop();
//             break;

//         case Main_SV:
//             MainSceneSV(sv, dsmh, dsch, testing_subject, time, number_of_questions);
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
// string a;
string a;
  GiaoDienDanhSachLop(dslh);

      GiaoDienDanhSachSinhVien(dslh,a);
        //GiaoDienDanhSachMon(dsmh);
   Deinitialize();
   return 0;

}