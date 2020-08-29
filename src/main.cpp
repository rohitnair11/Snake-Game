#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "mainmenu.h"
#include "player.h"
#include "record.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  bool beginGame = false;
  MainMenu mm;
  Record record;
  beginGame = mm.StartScreen();
  
  if(beginGame){
    Player player;
    player.SetName();
    player.PrintName();
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    record.SetPlayerData(player.GetName(), game.GetScore());
    std::cout << "Game has terminated successfully!\n";
    std::cout << "***********************************\n";
    std::cout << "Player Name: " << player.GetName() << "\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    std::cout << "Highest Score: " << record.GetHighestScore(player.GetName(), game.GetScore()) << "\n";
    
    return 0;
  }
}