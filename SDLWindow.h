#ifndef __SDLWINDOW__
#define __SDLWINDOW__

#include <SDL.h>
#include <SDL_ttf.h>

#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_RED   0xFF0000FF
#define COLOR_BLUE  0xFFFF0000
#define COLOR_GREEN 0xFF00FF00

class SDLWindow 
{
 public:
  union RGBA {
    struct {
      char red, green, blue, alpha;
    };
    Uint32 color;
  };
 
  SDLWindow();
  ~SDLWindow();
  void Init();
  void ClearScreen(Uint32 color);
  void setPixel(int x, int y, Uint32 color);
  void DrawRect(int x, int y, int width, int height, Uint32 color);
  void DrawCircle(int n_cx, int n_cy, int radius, Uint32 pixel);
  void DrawLine(int x1, int y1, int x2, int y2, Uint32 color);
  void Update();
 private:
  SDL_Window *win;
  SDL_Surface *screen_surface;
  SDL_Renderer *renderer;
  SDL_Rect window_geometry;
  TTF_Font *font;
  SDL_Surface *text_surface;
};

#endif //__SDLWINDOW__
