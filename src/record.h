#include <iostream>

using std::string;

class Record{
public:
  Record(){};
  void SetPlayerData(string name, int score);
  int GetHighestScore(string name, int score);
  void GetAllData();
private:
  
};