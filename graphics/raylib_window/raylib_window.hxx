#include <raylib.h>
#include "types/type_alias.hxx"

class RaylibWindow {
public:
  RaylibWindow(const u32 w, const u32 h, const char* title);

  void update();

  RaylibWindow& setTargetFPS(const u32 fps);

  ~RaylibWindow();
};

#ifdef RAYLIB_WINDOW_IMPL
RaylibWindow::RaylibWindow(const u32 w, const u32 h, const char* title) {
    InitWindow(w, h, title);
}

RaylibWindow& RaylibWindow::setTargetFPS(const u32 fps) {
  SetTargetFPS(fps);
  return this;
}

RaylibWindow::~RaylibWindow() {
  CloseWindow();
}
#endif
