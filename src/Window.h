#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <utility>

class Window {
private:
  SDL_Window *m_window{};
  SDL_Renderer *m_renderer{};
  int m_width, m_height;
  const char *m_title{};

  auto Init_SDL();
  auto Create_Window();
  auto Create_Renderer(SDL_Window *window);

public:
  Window(const char *title, int width, int height);
  virtual ~Window();
};