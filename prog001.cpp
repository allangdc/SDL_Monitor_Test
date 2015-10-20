// g++ prog001.cpp SDLWindow.cpp -o exec001 -lSDL2 -lSDL2_ttf -D_REENTRANT -I/usr/include/SDL2

#include <iostream>
#include "SDLWindow.h"

int main(int argc, char **argv) {
  SDLWindow sdl;
  sdl.Init();
  sdl.ClearScreen(COLOR_WHITE);
  sdl.DrawRect(10,50,300, 100, COLOR_GREEN);
  sdl.DrawCircle(200,200,150, COLOR_RED);
  sdl.DrawLine(10,10, 200,200, COLOR_BLUE);
  sdl.Update();
  SDL_Delay(6000);
  
  return 0;
}

/*
#define COLOR_WHITE   0xFFFFFFFF
#define COLOR_RED   0xFF0000FF
#define COLOR_BLUE   0xFFFF0000
#define COLOR_GREEN   0xFF00FF00

union RGBA {
  struct {
    char red, green, blue, alpha;
  };
  Uint32 color;
};

SDL_Window *win = NULL;
SDL_Surface *screen_surface = NULL;
SDL_Renderer *renderer = NULL;
SDL_Rect window_geometry = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600};

void Init(void);
void ClearScreen(Uint32 color);
void setPixel(int x, int y, Uint32 color);
void DrawRect(int x, int y, int width, int height, Uint32 color);
void DrawCircle(int n_cx, int n_cy, int radius, Uint32 pixel);
void DrawLine(int x1, int y1, int x2, int y2, Uint32 color);

int main(int argc, char **argv) {
  Init();  
  
  DrawRect(10,50,300, 100, COLOR_GREEN);
  DrawCircle(200,200,80, COLOR_RED);
  DrawLine(10,10, 200,200, COLOR_BLUE);
    
  SDL_RenderPresent( renderer );

  // Wait two seconds
  SDL_Delay(6000);
  
  //SDL_DestroyWindow(win);
  //SDL_Quit();
  
  return 0;
}

void Init(void) {
  // Initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  
  // Create Window
  win = SDL_CreateWindow("Window", window_geometry.x, window_geometry.y, window_geometry.w, window_geometry.h, SDL_WINDOW_SHOWN);
  
  // Get window surface
  screen_surface = SDL_GetWindowSurface(win);
  
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  ClearScreen(COLOR_WHITE);
}

void ClearScreen(Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
	SDL_RenderClear(renderer);
}

void DrawRect(int x, int y, int width, int height, Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_Rect fill_rect = {x, y, width, height};  
	SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
	SDL_RenderDrawRect(renderer, &fill_rect);
}

void setPixel(int x, int y, Uint32 color)
{
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
  SDL_RenderDrawPoint(renderer, x, y);
}

void DrawCircle(int n_cx, int n_cy, int radius, Uint32 color)
{
  double error = (double) -radius;
  double x = (double)radius - 0.5;
  double y = (double) 0.5;
  double cx = n_cx - 0.5;
  double cy = n_cy - 0.5;

  while (x >= y)
  {
    setPixel((int)(cx + x), (int)(cy + y), color);
    setPixel((int)(cx + y), (int)(cy + x), color);

    if (x != 0) {
      setPixel((int)(cx - x), (int)(cy + y), color);
      setPixel((int)(cx + y), (int)(cy - x), color);
    }

    if (y != 0) {
      setPixel((int)(cx + x), (int)(cy - y), color);
      setPixel((int)(cx - y), (int)(cy + x), color);
    }

    if (x != 0 && y != 0) {
      setPixel((int)(cx - x), (int)(cy - y), color);
      setPixel((int)(cx - y), (int)(cy - x), color);
    }

    error += y;
    ++y;
    error += y;

    if (error >= 0) {
      --x;
      error -= x;
      error -= x;
    }
  }
}

void DrawLine(int x1, int y1, int x2, int y2, Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

// */






