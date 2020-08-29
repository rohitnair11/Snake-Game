#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "player.h"
#include "game.h"
#include "record.h"

using std::string;
using std::cout;

void Record::SetPlayerData(string name, int score){
  std::ofstream file;
  std::map<string, int> game_data;
  game_data.insert(std::make_pair(name, score));
  file.open("records.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!file.is_open()){
    std::cout << "xxxxx Error in opening file xxxxx" << std::endl;
  }
  else{
    for (const auto i:game_data){
      file << i.first << " " << i.second << "\n";
    }
    file.close();
  }
}

int Record::GetHighestScore(string name, int score){
  string pname, highest_score, line;
  int temp_score = 0;
  std::ifstream filestream("../build/records.txt");
  if (filestream.is_open()){
    while (std::getline(filestream, line)){
      std::istringstream linestream(line);
      while (linestream >> pname >> highest_score){
        if(pname == name){
          if(temp_score < stoi(highest_score)){
            temp_score = stoi(highest_score);
          }
        }
      }
    }
    if(temp_score == 0){
      return score;
    }
    else{
      return temp_score;
    }
    filestream.close();
  }
  else
  {
    std::ofstream outfile("records.txt");
    std::cout << "xxxxx Error reading data from file xxxxx" << std::endl;
  }
  return -1;
}

void Record::GetAllData(){
  string pname, highest_score, line;
  std::ifstream filestream("../build/records.txt");
  if (filestream.is_open()){
    while (std::getline(filestream, line)){
      std::istringstream linestream(line);
      while (linestream >> pname >> highest_score){
        cout << pname << "          " << highest_score << std::endl;
      }
    }
    filestream.close();
  }
  else
  {
    std::ofstream outfile("records.txt");
    std::cout << "xxxxx Error reading data from file xxxxx" << std::endl;
  }
}