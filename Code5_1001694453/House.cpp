// House Class Template

#include "House.h"


House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name}, CandyRankingMap{CandyRanking}
{
}

std::string House::ringDoorbell(std::ostringstream &path)
{
	/* lock the door mutex */
	Door.lock();

	path << "*";
	/* put this_thread to sleep for 3 seconds */
	std :: this_thread::sleep_for(std :: chrono::seconds(3));
	
	//Pick a candy from the CandyRankingMap
	int candy = rand() % (CandyRankingMap.size()) + 1;

	/* unlock the door mutex */
	Door.unlock();
	return CandyRankingMap[candy];
}