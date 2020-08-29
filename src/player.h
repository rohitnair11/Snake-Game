#include <iostream>
#include <string>

using std::cout;
using std::string;

class Player {
public:
  Player(){
    cout << "******Player Profile******" << std::endl;
  }
//   ~Player();
  void SetName();
  string GetName();
  void PrintName();

private:
  string _name;
};