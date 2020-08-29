#include <iostream>
#include <algorithm>

#include "mainmenu.h"
#include "record.h"

using std::cout;

bool MainMenu::StartScreen(){
  int choice;
  
  cout << "*****Let's Play the Snakes*****" << std::endl;
  cout << "Press 1 to Start the Game" << std::endl;
  cout << "Press 2 to View Player Stats" << std::endl;
  cout << "Press 3 to Quit" << std::endl;
  
  std::cin >> choice;
  
  while (choice != 1 && choice != 2 && choice != 3) 
  {
    cout << "Please enter a valid choice" << std::endl;
    std::cin >> choice;
  }
  
  if(choice == 1) {
    return true;
  }
  else if(choice == 2){
    Record record;
    cout << "*********Stats*********" << std::endl;
    cout << "Player Name     Score" << std::endl;
    record.GetAllData();
  }
  else{
    return false;
  }
}