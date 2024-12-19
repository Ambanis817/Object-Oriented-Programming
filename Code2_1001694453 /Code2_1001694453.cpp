// Samuel Ambani 1001694453
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>



using namespace std;


#define faces 6
#define rolls 3
#define tr 23
#define rice 5

std::string TestRollDice(std::vector<int> &dice);

void RollDice(vector<int> &dicevector)
{
   srand ((unsigned)time(0));
   for(int i = 0; i < 5 && dicevector.size() < 5 ;i++)
   {
    int b = rand() % faces + 1;
    dicevector.push_back(b);
    
   }
}
void PrintRoll(vector <int> &dicevector)
{
 
 
   for(int n :dicevector)
   {
     cout << " "<< n;
   }

}
void FillHowMany(vector <int> &dicevector,vector <int> &howmany)
{

      for (int &s: howmany)
      {
        s = 0;
     }  
     
    for(int i : dicevector)
     {
       howmany[i-1]++;
     }
}
void PickDice(vector <int> &dicevector)
{
   char keep1;
   vector <int> temp;
 
  cout << "Pick which dice to reroll. Answer Y at prompt to keep that die.\n"<< endl;
    temp = dicevector;
   for(int s: temp)
   {
   cout << "Keep " << s << "? ";
   cin >> keep1;

   if (keep1 == 'n'|| keep1 == 'N')
   {

   auto i = find(begin(dicevector),end(dicevector),s);
   dicevector.erase(i);
   }
   }
}

int main (int argc,char *argv[])
{


 vector <int> h(faces);
int count = 0;
char letter;
string result ;

int pass = 0;
int fail = 0;
char check;
string t;
string para = "TEST";
int rest;
vector <int> dicevector;
do
{
  int ofAkind = 0;
int FullHouse = 0;
int Twopair= 0;
int CPPSlam = 0;
int LargeStraight= 0;
int smallStraight = 0;



if(argc == 2 && argv[1] == para)
{
t = TestRollDice(dicevector);
check = 'y';
 rest = tr;

}
else
{
  RollDice(dicevector);
  check = 'n';
  rest = rolls +1 ;
}

 

 
   cout << "\nYou rolled " << endl;
 
 
 
 PrintRoll(dicevector);
 FillHowMany(dicevector,h);


  for(int c : h)
  {
    if (c == 3)
    {
      FullHouse = FullHouse +3;
    }
    if (c == 2)
    {
      FullHouse = FullHouse +2;
      Twopair++;
    }
    if (c==5)
    {
      CPPSlam ++;
    }
    if (c==1)
    {
      LargeStraight++;
    }
    else if(c == 0 && LargeStraight > 0 && LargeStraight < 5)
    {
     LargeStraight = 0;
    }
    if (c >= 1)
    {
      smallStraight ++;
    }
    
    else if(c == 0 && smallStraight > 0 && smallStraight < 4)
    {
      smallStraight = 0;
    }
    if (c == 4)
    {
      ofAkind = 4;
    }
    if (c == 3)
    {
      ofAkind = 3;
    }
    
  }
    if (LargeStraight == 5)
    {
      cout << "\n Large Straight \n"<< endl;
      result = "Large Straight";
    }
    else if (smallStraight >= 4)
    {
      cout << "\nSmall Straight \n"<< endl;
      result = "Small Straight";
    }
    else if (FullHouse == 5)
    {
       cout << "\nFull House \n"<< endl;
       result = "Full House";

    }

    else if (CPPSlam ==1)
    {
       cout << "\nC++Slam!\n"<< endl;
        result = "C++Slam!";
       
    }
    else if (ofAkind == 4)
    {
       cout << "\nFour of a Kind\n"<< endl;
       result = "Four of a Kind";
    }
      else if (ofAkind == 3)
    {
      cout << "\nThree of a Kind\n"<< endl;
      result = "Three of a Kind";
    }
      else if (Twopair == 2)
    {
       cout << "\nTwo Pair"<< endl;
        result = "Two Pair";
    }
 
    else
    {
      cout << "\nYou have nothing\n\n"<< endl;
    }

    if (check == 'y'|| check == 'Y')
    {
    if (result == t)
    {
      pass++;
    
      cout << "pass\n"<< endl;

    }
    else
    {
      cout << "fail\n"<< endl;
      fail ++;
    }
    
    }
    
    
   
    count ++; 
    if(check == 'n' )
    {
      cout << "Do you want to reroll? ";
      cin >> letter;
    if (letter == 'y'|| letter== 'Y')
    {
      PickDice(dicevector);
    }
    }
   
}while(count < rest && letter != 'n'&& letter != 'N');





 
if (check == 'y' || check == 'Y')
{
cout << "out of 23 tests, " << pass << " tests passed and  " << fail << " tests failed."<<endl;
}
else
{
RollDice(dicevector);
cout << "\nYou rolled " << endl;
PrintRoll(dicevector);
}



    









}
