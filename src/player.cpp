#include <iostream>
#include <string>

#include "player.h"

using std::string;
using std::cout;

void Player::SetName(){
  string name;
  cout << "Enter your Name ---> ";
  std::cin >> name;
  _name = name;
}

string Player::GetName(){
  return _name;
}

void Player::PrintName(){
  cout << "Welcome " << _name << std::endl;
}
