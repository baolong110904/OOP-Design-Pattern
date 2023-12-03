#include "WindowsSetting.cpp"
#include <conio.h>
// Có a trai nào dùng VS thì tìm cách sửa cái này thành .h giùm, e lười quá

using namespace std;

int main() {
  WindowsSetting wds;
  wds.setWindowSize(40, 20);
  wds.setScreenBufferSize(40, 20);
  wds.disableResizeWindow();
  wds.disableCtrButton(false, true, true);
  wds.disableScrollbar();
  wds.disableSelect();
  wds.hideCursor();
  wds.setConsoleTitle("Facade");
  wds.setUnicodeOutput();
  wds.setColor("yellow", "red");

  wds.goTo(17, 9);
  cout << "         ";
  wds.goTo(17, 10);
  cout << "    ★    ";
  wds.goTo(17, 11);
  cout << "         ";

  char pause = getch();
  return 0;
}

// Build ra rồi chạy file .exe bằng quyền admin nha