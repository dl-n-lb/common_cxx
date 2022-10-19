#include "types/type_alias.hxx"
#include "raylib.h"
#include <functional>


// TODO: IS THERE A NEATER WAY TO ACUTALLY DRAW STUFF? PROBABLY
// CAN I BE ASSED TO DO IT?
// IF SOMEONE TELLS ME I HAVE TO, SURE
class RaylibRenderer {
public:
  RaylibRenderer();
  RaylibRenderer(Color col);

  void Draw(std::function<void(void)> fn);

  ~RaylibRenderer();
private:
};

#ifdef RAYLIB_RENDERER_IMPL
RaylibRenderer::RaylibRenderer() {
  BeginDrawing();
}

RaylibRenderer::RaylibRenderer(Color col) {
  BeginDrawing();
  printf("Cleared Background");
  ClearBackground(col);
}

void Draw(std::function<void(void)> fn) {
  fn();
}

RaylibRenderer::~RaylibRenderer() {
  EndDrawing();
}
#endif
