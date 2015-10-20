#include "SDLWindow.h"

SDLWindow::SDLWindow() {
  win = NULL;
  screen_surface = NULL;
  renderer = NULL;
  window_geometry.x = SDL_WINDOWPOS_UNDEFINED;
  window_geometry.y = SDL_WINDOWPOS_UNDEFINED;
  window_geometry.w = 800;
  window_geometry.h = 600;
  font = NULL;
  text_surface = NULL;
}

SDLWindow::~SDLWindow() {
}

void SDLWindow::Update() {
  SDL_RenderPresent(renderer);
}

void SDLWindow::Init() {
  // Initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  
  // Create Window
  win = SDL_CreateWindow("Window", window_geometry.x, window_geometry.y, window_geometry.w, window_geometry.h, SDL_WINDOW_SHOWN);
  
  // Get window surface
  screen_surface = SDL_GetWindowSurface(win);
  
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  
  TTF_Init();
  font = TTF_OpenFont("MONOSPACE.TTF", 13);
  SDL_Color fore = {255,255,255};
  SDL_Color back = {0,0,255};
  SDL_Surface *text_surface = TTF_RenderText_Shaded(font, "This is my text.", fore, back);
  SDL_Rect text_location = {100, 100, 0, 0};
  SDL_BlitSurface(text_surface, NULL, screen_surface, &text_location);
}

void SDLWindow::ClearScreen(Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
	SDL_RenderClear(renderer);
}

void SDLWindow::DrawRect(int x, int y, int width, int height, Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_Rect fill_rect = {x, y, width, height};  
	SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
	SDL_RenderDrawRect(renderer, &fill_rect);
}

void SDLWindow::setPixel(int x, int y, Uint32 color)
{
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
  SDL_RenderDrawPoint(renderer, x, y);
}

void SDLWindow::DrawCircle(int n_cx, int n_cy, int radius, Uint32 color)
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

void SDLWindow::DrawLine(int x1, int y1, int x2, int y2, Uint32 color) {
  union RGBA rgba;
  rgba.color = color;
  SDL_SetRenderDrawColor(renderer, rgba.red, rgba.green, rgba.blue, rgba.alpha);
  SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}






