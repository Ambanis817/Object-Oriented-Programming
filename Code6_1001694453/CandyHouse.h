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
#include "House.h"

class CandyHouse : public House 
{

 public:
    CandyHouse(std::string Name, std::map<int,std::string>CandyRanking);
    ~CandyHouse();
    std::string ringDoorbell(std::ostringstream &path);

};