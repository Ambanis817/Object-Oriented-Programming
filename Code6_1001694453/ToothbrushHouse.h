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
#include <iostream>
#include "House.h"

class ToothbrushHouse : public House
{

public:
    ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking);

    ~ToothbrushHouse();
     std::string ringDoorbell(std::ostringstream &path);

};
