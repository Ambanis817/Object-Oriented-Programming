// Treat or Tricker class header file template

/* add the necessary includes */

/* add an include guard called _TOT_H */

#ifndef _TOT_H
#define _TOT_H

#include <vector>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include<new>
#include "House.h"


class TrickOrTreater
{
	/* create friend function prototype */
	friend std::ostream& operator<<(std :: ostream &output,TrickOrTreater &TOT);
	
	public :
		/* create the prototype for the constructor based on TrickOrTreater.cpp */
		TrickOrTreater(std::string Name, std::vector<House*>List);
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int); 
		std::string getPath();
		static int ImDone;
		
		
	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		/* declare a map named Bucket of type string,int */
		std :: map <std :: string,int>Bucket;
		/* declare a vector name ListOfHouses of type pointer to House */
		std :: vector <House*> ListOfHouses;
};

#endif
