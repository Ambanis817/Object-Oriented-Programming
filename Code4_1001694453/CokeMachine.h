//  SAMUEL AMBANI 1001694453
#ifndef COKE_MACHINE_H
#define COKE_MACHINE_H
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
enum  Action
{
    OK ,
    CHANGE,
    NOINVENTORY,
    NOCHANGE,
    INSUFFCIENT

};
class CokeMachine
{

    friend std :: string CreateCokeOutputLine(std :: vector <CokeMachine> &machine);
    friend std::ostream& operator << (std :: ostream &output, CokeMachine &coke);
  public : 
    CokeMachine (std ::string name= "New Machine",int cost = 50,int change=500,int inventory=100);
    CokeMachine (const CokeMachine &CopyMachine);
    ~ CokeMachine();
    std :: string CreateCokeOutputLine(std :: vector <CokeMachine> &machine);
    std :: string getMachineName();
    bool buyACoke(int payment,int &action,std :: string &change);
    int getinventoryLevel();
    int getMaxinventoryCapacity();
    bool incrementinventory(int amountToAdd);
    std :: string  getChangeLevel();
    bool incrementChangeLevel(int amountToAdd);
    std :: string getMaxChangeCapacity();
    std :: string getCokePrice ();
    std :: string displayMoney(int amount);
    void setCokePrice (int newCokePrice);
    void setMachineName (std :: string newmachinename);

   
 private: 
    std::string machineName;
    int changelevel;
    int maxChangeCapacity = 5000;
    int CokePrice;
    int inventoryLevel;
    int maxinventoryCapacity = 100;
    std :: string cents;
    std ::string dollars;
    std :: string money;

};
#endif