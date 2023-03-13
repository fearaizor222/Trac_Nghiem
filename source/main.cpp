#include "../header/raylib.h"

const int WIDTH  = 1200;
const int HEIGHT = 800;
const Image logo = LoadImage("../style/240px-Logo_PTIT_University.png");

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Phần mềm trắc nghiệm");
    SetWindowIcon(logo);
    Font font = LoadFontEx("../style/TimesNewRoman.ttf", 30, 0, 8192);
    Texture2D login_logo = LoadTextureFromImage(logo);

    while(!WindowShouldClose()){
        int wid_win = GetRenderWidth();
        int hei_win = GetRenderHeight();

        Vector2 size_dang_nhap = MeasureTextEx(font, "Đăng nhập", 30, 5);
        size_dang_nhap.x  = wid_win/2 - (size_dang_nhap.x)/2;
        size_dang_nhap.y  = hei_win/2 - (size_dang_nhap.y)/2 - 50;

        Vector2 size_tai_khoan = MeasureTextEx(font, "ID:", 30, 5);
        size_tai_khoan.x  = wid_win/2 - (size_tai_khoan.x)/2 - 150;
        size_tai_khoan.y  = hei_win/2 - (size_tai_khoan.y)/2;

        Vector2 size_pass = MeasureTextEx(font, "Pass:", 30, 5);
        size_pass.x  = wid_win/2 - (size_pass.x)/2 - 160;
        size_pass.y  = hei_win/2 - (size_pass.y)/2 + 60;

        BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(login_logo, wid_win/2 - 250/2, hei_win/2 - 50/2 - 240 - 50, WHITE);
            DrawTextEx(font, "Đăng nhập", size_dang_nhap, 30, 5, BLACK);
            DrawTextEx(font, "ID:", size_tai_khoan, 30, 2, BLACK);
            DrawTextEx(font, "Pass:", size_pass, 30, 2, BLACK);
            DrawRectangleLines(wid_win/2 - 250/2, hei_win/2 - 50/2, 240, 50, BLACK);
            DrawRectangleLines(wid_win/2 - 250/2, hei_win/2 + 70/2, 240, 50, BLACK);
        EndDrawing();
    }

    UnloadFont(font);
    UnloadImage(logo);
    UnloadTexture(login_logo);
    CloseWindow();
    return 0;
}

/*******************************************************************************************
*
*   raylib [text] example - Input Box
*
*   Example originally created with raylib 1.7, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2017-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

// #include "../header/raylib.h"

// #define MAX_INPUT_CHARS     9

// //------------------------------------------------------------------------------------
// // Program main entry point
// //------------------------------------------------------------------------------------
// int main(void)
// {
//     // Initialization
//     //--------------------------------------------------------------------------------------
//     const int screenWidth = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth, screenHeight, "raylib [text] example - input box");

//     char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
//     int letterCount = 0;

//     Rectangle textBox = { screenWidth/2.0f - 100, 180, 225, 50 };
//     bool mouseOnText = false;
//     Vector2 mouse_pos;
//     int framesCounter = 0;

//     SetTargetFPS(10);               // Set our game to run at 10 frames-per-second
//     //--------------------------------------------------------------------------------------

//     // Main game loop
//     while (!WindowShouldClose())    // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------
        
        
//         if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) mouse_pos = GetMousePosition();

//         if (CheckCollisionPointRec(mouse_pos, textBox)) mouseOnText = true;
//         else mouseOnText = false;

//         if (mouseOnText)
//         {
//             // Set the window's cursor to the I-Beam
//             SetMouseCursor(MOUSE_CURSOR_IBEAM);

//             // Get char pressed (unicode character) on the queue
//             int key = GetCharPressed();

//             // Check if more characters have been pressed on the same frame
//             while (key > 0)
//             {
//                 // NOTE: Only allow keys in range [32..125]
//                 if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
//                 {
//                     name[letterCount] = (char)key;
//                     name[letterCount+1] = '\0'; // Add null terminator at the end of the string.
//                     letterCount++;
//                 }

//                 key = GetCharPressed();  // Check next character in the queue
//             }

//             if (IsKeyPressed(KEY_BACKSPACE))
//             {
//                 letterCount--;
//                 if (letterCount < 0) letterCount = 0;
//                 name[letterCount] = '\0';
//             }
//         }
//         else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

//         if (mouseOnText) framesCounter++;
//         else framesCounter = 0;
//         //----------------------------------------------------------------------------------

//         // Draw
//         //----------------------------------------------------------------------------------
//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

//             DrawRectangleRec(textBox, LIGHTGRAY);
//             if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
//             else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

//             DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

//             DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

//             if (mouseOnText)
//             {
//                 if (letterCount < MAX_INPUT_CHARS)
//                 {
//                     // Draw blinking underscore char
//                     if (((framesCounter/5)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
//                 }
//                 else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
//             }

//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     CloseWindow();        // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }

// // Check if any key is pressed
// // NOTE: We limit keys check to keys between 32 (KEY_SPACE) and 126
// bool IsAnyKeyPressed()
// {
//     bool keyPressed = false;
//     int key = GetKeyPressed();

//     if ((key >= 32) && (key <= 126)) keyPressed = true;

//     return keyPressed;
// }