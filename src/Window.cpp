#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <stdexcept>

auto Window::Init_SDL() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw std::runtime_error("Could not init SDL!");
  }
}

auto Window::Create_Window() {
  m_window =
      SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       m_width, m_height, SDL_WINDOW_OPENGL);
  if (m_window == nullptr) {
    throw std::runtime_error("Could not create window!");
  } // if (m_window == nullptr)
} // auto IWindow::Create_Window()

auto Window::Create_Renderer(SDL_Window *window) {
  m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == nullptr) {
    SDL_DestroyWindow(window);
    throw std::runtime_error("Could not create Renderer!");
  }
}

Window::Window(const char *title, int width, int height) {
  std::cout << "HELLO FROM WINDOW!\n";
  m_title = title;
  m_width = width;
  m_height = height;
  Init_SDL();
  Create_Window();
  Create_Renderer(m_window);
} // auto IWindow::Create_Renderer(SDL_Window *window

Window::~Window() {
  std::cout << "WINDOW DESTRUCTOR\n";
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}