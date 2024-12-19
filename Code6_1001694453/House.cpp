// House Class Template

#include "House.h"


House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name},CandyRankingMap{CandyRanking}
{
}
House::~House()
{
	std :: cout << "HOUSE" << std :: endl;
}

