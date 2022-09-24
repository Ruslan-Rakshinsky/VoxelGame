#include "Game.h"
#include "Window.h"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <locale>
#include <utility>

auto main() -> int {
  try {
    Game game("test", 800, 600);

    std::cout << "Hello from main!\n";

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    SDL_Quit();
    return EXIT_FAILURE;
  }
}
