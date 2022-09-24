#pragma once
#include "Window.h"
#include <iostream>

class Game : public Window {
public:
  Game(const char *title, int width, int height)
      : Window(title, width, height) {
    std::cout << "HELLO FROM GAME!\n";
  }
  virtual ~Game() { std::cout << "Game Destructor!\n"; }

private:
};