#include <iostream>
#include <windows.h>
#include <map>

using namespace std;

class WindowsSetting {
  public:
    WindowsSetting() {};
    ~WindowsSetting() {};
    void setWindowSize(int width, int height) {
      HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
      SMALL_RECT WindowSize;
      WindowSize.Top = 0;
      WindowSize.Left = 0;
      WindowSize.Right = width;
      WindowSize.Bottom = height;
      SetConsoleWindowInfo(hStdout, 1, &WindowSize);
    }
    void setScreenBufferSize(int width, int height) {
      HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD NewSize;
      NewSize.X = width;
      NewSize.Y = height;
      SetConsoleScreenBufferSize(hStdout, NewSize);
    }
    void disableResizeWindow() {
      HWND hWnd = GetConsoleWindow();
      SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
    }
    void disableCtrButton(bool close, bool min, bool max) {
      HWND hWnd = GetConsoleWindow();
      HMENU hMenu = GetSystemMenu(hWnd, false);
      if (close) {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
      }
      if (min) {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
      }
      if (max) {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
      }
    }
    void disableScrollbar() {
      HWND hWnd = GetConsoleWindow();
      ShowScrollBar(hWnd, SB_BOTH, false);
    }
    void disableSelect() {
      HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
      SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
    }
    void hideCursor() {
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO ConCurInf;
      ConCurInf.dwSize = 10;
      ConCurInf.bVisible = false;
      SetConsoleCursorInfo(handle, &ConCurInf);
    }
    void setConsoleTitle(string title) {
      SetConsoleTitle(title.c_str()); // Máy tụi bậy có bị lỗi chỗ này ko, dhs máy t báo lỗi mà vẫn chạy dc
    }
    void setUnicodeOutput() {
      SetConsoleOutputCP(65001);
    }
    void setColor(string textColor, string backgroundColor) {
      map <string, int> colorMap;
      colorMap["black"] = 0;
      colorMap["blue"] = 1;
      colorMap["green"] = 2;
      colorMap["aqua"] = 3;
      colorMap["red"] = 4;
      colorMap["purple"] = 5;
      colorMap["yellow"] = 6;
      colorMap["white"] = 7;
      colorMap["gray"] = 8;
      colorMap["lightblue"] = 9;
      colorMap["lightgreen"] = 10;
      colorMap["lightaqua"] = 11;
      colorMap["lightred"] = 12;
      colorMap["lightpurple"] = 13;
      colorMap["lightyellow"] = 14;
      colorMap["brightwhite"] = 15;
      HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
      int color_code = colorMap[backgroundColor] * 16 + colorMap[textColor];
      SetConsoleTextAttribute(hStdout, color_code);
    }
    void goTo(int posX, int posY) {
      HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD Position;
      Position.X = posX;
      Position.Y = posY;
    	SetConsoleCursorPosition(hStdout, Position);
    }
};