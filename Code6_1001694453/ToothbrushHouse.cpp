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
#include "ToothbrushHouse.h"
#include "House.h"


ToothbrushHouse::ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking)
	:House(houseName,CandyRanking)
{
}
ToothbrushHouse::~ToothbrushHouse()
{
	std :: cout <<"TOOTHBRUSHHOUSE"<< std ::endl;
}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
	/* lock the door mutex */
	Door.lock();
	path << "-"; 

	std :: this_thread::sleep_for(std :: chrono::seconds(3));
	
	Door.unlock();
	return "TOOTHBRUSH";
}