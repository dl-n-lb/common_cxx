#include <raylib.h>
#include "types/type_alias.hxx"
#include <functional>
#include "graphics/raylib_window/raylib_renderer.hxx"

class RaylibWindow {
public:
  RaylibWindow(const u32 w, const u32 h, const char* title);

  bool shouldClose();

  void Update(std::function<void(RaylibWindow*)> update_fn);

  void setTargetFPS(const u32 fps);

  RaylibRenderer getRenderer(Color col);

  ~RaylibWindow();
};

#ifdef RAYLIB_WINDOW_IMPL
RaylibWindow::RaylibWindow(const u32 w, const u32 h, const char* title) {
    InitWindow(w, h, title);
}

void RaylibWindow::setTargetFPS(const u32 fps) {
  SetTargetFPS(fps);
}

RaylibWindow::~RaylibWindow() {
  CloseWindow();
}

bool RaylibWindow::shouldClose() {
 return WindowShouldClose();
}

RaylibRenderer RaylibWindow::getRenderer(Color col) {
  printf("Created Renderer\n");
  return RaylibRenderer(col);
}

void RaylibWindow::Update(std::function<void(RaylibWindow*)> update_fn) {
  update_fn(this);
  printf("Updated Screen Contents\n");
  SwapScreenBuffer();
  printf("Swapped buffers\n");
}

#endif
