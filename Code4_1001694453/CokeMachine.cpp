//  SAMUEL AMBANI 1001694453
#include "CokeMachine.h"
#include <string>
#include <sstream>
#include <vector>

std :: ostream& operator << (std :: ostream &output, CokeMachine &coke)
{
    output<< "\n"<< "Machine Name : "<< coke.machineName
    << "\n\nCurrent Iventory Level " << coke.getinventoryLevel()
    << "\nMax Inventory Capacity " << coke.getMaxinventoryCapacity()
    << "\nCurrent Change Level " << coke.getChangeLevel()
    << "\nMax Change Capacity " << coke.getMaxChangeCapacity()
    << "\nCurrent Coke Price " << coke.getCokePrice();
    return output;
}

std::string CreateCokeOutputLine(std :: vector <CokeMachine> &machine)
{
    std::stringstream output;
    for (int  i = 0; i < machine.size(); i++)
    {
       output<<machine.at(i).machineName << "|"<< machine.at(i).CokePrice << "|"<< machine.at(i).changelevel << "|"<< machine.at(i).inventoryLevel << "\n";
    }
     return  output.str();
}

    CokeMachine::CokeMachine (std ::string name,int cost ,int change,int inventory)
        :machineName{name},CokePrice{cost},changelevel{change},inventoryLevel{inventory}
    {
    }

    CokeMachine::CokeMachine (const CokeMachine &CopyMachine)
        :machineName{CopyMachine.machineName},CokePrice{CopyMachine.CokePrice},changelevel{CopyMachine.changelevel},inventoryLevel{CopyMachine.inventoryLevel}
    {
    }
    CokeMachine::~CokeMachine ()
    {
        std::cout << "CokeMachine " << machineName << " has been destroyed\n";
    }

    std :: string CokeMachine ::getMachineName()
    {
        return machineName;
    }
    bool CokeMachine :: buyACoke(int payment,int &action,std :: string &change)
    {
      if (changelevel == maxChangeCapacity)
      {
        return false;  
      }
      if (payment < CokePrice)
      {
         action = INSUFFCIENT;
         return false;
      }
      else if (changelevel == 0 || payment > maxChangeCapacity || payment> changelevel)
      {
          action = NOCHANGE;
          return false;
      }
      else if (inventoryLevel== 0)
      {
          action = NOINVENTORY;
          return false;
      }
      else if (payment == CokePrice)
      {
          action = CHANGE;
          changelevel = changelevel + payment;
          change = displayMoney(changelevel);
          inventoryLevel--;
          return true;
      }
       else if (CokePrice < payment)
      {
          action = OK;
          int p = payment - CokePrice;
          change = displayMoney(p);
          inventoryLevel --;
          changelevel = changelevel + (payment - p);
          return true;
      }
      return 0;
      
    }
    int CokeMachine :: getinventoryLevel()
    {
        return inventoryLevel;
    }
    int CokeMachine :: getMaxinventoryCapacity()
    {
        return maxinventoryCapacity;
    }
    bool CokeMachine :: incrementinventory(int amountToAdd)
    {
         if (inventoryLevel + amountToAdd > maxinventoryCapacity )
        {
            return false;
        }
        else
        {
            inventoryLevel = inventoryLevel + amountToAdd;
            return true;
        }
    }
     std :: string CokeMachine :: getChangeLevel()
    {
       return displayMoney(changelevel);
    }
    bool CokeMachine :: incrementChangeLevel(int amountToAdd)
    {
        if (changelevel + amountToAdd >maxChangeCapacity )
        {
            return false;
        }
        else
        {
            changelevel = changelevel + amountToAdd;
            return true;
        }

    }


    std :: string CokeMachine :: getMaxChangeCapacity()
    {
        return displayMoney(maxChangeCapacity);
    }
     std ::  string CokeMachine :: getCokePrice ()
    {
        return displayMoney(CokePrice);
    }
    std :: string CokeMachine :: displayMoney(int amount)
    {
    std::string dollars {std ::to_string (amount/100)};
    std::string cents {std ::to_string(amount%100)};
    std::string money( "$"+dollars + "."+(cents.size()== 1? "0": "")+ cents); // puts your long number 
    return money;
    }
    void CokeMachine::setCokePrice (int newCokePrice)
    {
        CokePrice = newCokePrice;
    }
    void CokeMachine::setMachineName (std :: string newmachinename)
    {
        machineName = newmachinename;
    }

    