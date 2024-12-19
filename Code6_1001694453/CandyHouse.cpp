#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <sstream>
#include <thread>
#include <map>
#include <stdexcept>
#include <fstream>
#include<new>
#include <cstring>
#include "CandyHouse.h"
#include "House.h"



CandyHouse::CandyHouse(std::string Name, std::map<int,std::string>CandyRanking)
	:House(houseName,CandyRanking)
{
}
CandyHouse::~CandyHouse()
{
  std :: cout <<"CANDYHOUSE"<< std :: endl;
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
	/* lock the door mutex */
	Door.lock();
	path << "+"; 
	std :: this_thread::sleep_for(std :: chrono::seconds(3));

    int C = rand ()% CandyRankingMap.size() + 1;
	Door.unlock();
	return CandyRankingMap[C];
}


