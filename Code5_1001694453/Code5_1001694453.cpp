// Samuel Ambani 1001694453
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
#include "TrickOrTreater.h"



using namespace std;

void get_command_line_params(int argc, char *argv[], string& TOTfile, string& Housefile, string& Candyfile)
{
	/* if argc is 4, then put argv[1] in TOTfile, argv[2] in Housefile and argv[3] in Candyfile
	/* else throw an invalid_argument with the message shown in the output */
   
    if (argc == 4)
    {
        TOTfile = argv[1];
        Housefile = argv[2];
        Candyfile = argv[3];
    }
    else
    {
        throw std::invalid_argument("\nMissing command line parameters - Usage :");
    }
}


int main(int argc, char *argv[])
{
	string TOTFilename, HouseFilename, CandyFilename;

	/* create a map named CandyRankingMap of type int,string */
    map<int,string>CandyRankingMap;
    
	string CandyLine;
	char CandyLineA[50] = {};
	string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;
	/* create a vector named Houses of type pointers to House */
    vector<House*>Houses;
	string HouseLine;

	
    vector<TrickOrTreater> TOTs;
	string TotLine;
	
	/* declare an ostringstream named HouseHeading */
	ostringstream HouseHeading;
	srand(time(NULL));
	
	/* create a try-catch block for function get_command_line_params */
    try
    {
        get_command_line_params(argc,argv,TOTFilename,HouseFilename,CandyFilename);
    }
     catch(invalid_argument& say)
    {
        cerr << say.what() << endl;
        exit(0);
    }
    

	/* open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */
    ifstream TOTFH;
	TOTFH.open(TOTFilename);
    ifstream HouseFH;
	HouseFH.open(HouseFilename);
    ifstream CandyFH;
	CandyFH.open(CandyFilename);



	while (getline(CandyFH,CandyLine))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
		/* call insert() and make_pair() with CandyRanking and CandyName */
        CandyRankingMap.insert(make_pair(CandyRanking,CandyName));
	}
	/* Close the Candy file - CandyFH */
    CandyFH.close();

	
	HouseHeading << "          ";
	
	while (getline(HouseFH,HouseLine))
	{
		/* in one line - use new to allocate a House object that is constructed by    */
		Houses.push_back(new House{HouseLine,CandyRankingMap});
        
		/* passing HouseLine and CandyRankingMap and push_back the object into Houses */

		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";
	}
	HouseHeading << endl << endl;
	/* Close the House file - HouseFH */
    HouseFH.close();

	/* Create all of the Trick or Treaters */
	while (getline(TOTFH,TotLine))
	{
		TOTs.push_back(TrickOrTreater(TotLine, Houses));
	}
	/* Close the TOT file - TOTFH */
    TOTFH.close();

	/* Start all of the trick or treaters using a range based for loop over vector TOT */
    for (TrickOrTreater& trick : TOTs)
    {
       trick.startThread();
    }

	/* call function startThread() for each iterator for each pass through the loop */

	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << HouseHeading.str();

		for (TrickOrTreater& T : TOTs) 
		{
			cout << T.getPath() << T.getName()<< endl;
        }
		/* put this_thread to sleep for 5 milliseconds */
        this_thread::sleep_for(chrono::milliseconds(5));
	
    }

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << HouseHeading.str();

	for (TrickOrTreater& o : TOTs) 
	{
		cout << o.getPath() << o.getName()<< endl;
	}
	
	for (TrickOrTreater& t: TOTs)
	{
		cout << t;
	}

	for (TrickOrTreater& s : TOTs)
	{
		s.joinThread();
	}

	for (auto D : Houses )
	{
		delete D ;
	}
	cout <<"\n";
	return 0;
}