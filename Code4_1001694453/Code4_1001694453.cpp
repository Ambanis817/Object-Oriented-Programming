//  SAMUEL AMBANI 1001694453

#include <iostream>
#include <vector>
#include <string>
#include "CokeMachine.h"
#include "CokeLib.h"
#include <fstream>
#include <sstream>

using namespace std;


int main (int argc,char *argv[])
{
    CokeMachine MyCokeMachine;
    int choice {};
    int pay {};
    string change {}; 
    int action {};
    int inventroy{};
    int changeadd {};
    bool check{};
    bool nextcheck {};
    bool checkchange{};
    string newmachineName {};
    int newprice {};
    vector <CokeMachine> SetofCokeMachines;
    ifstream CokeInputFile;
    ofstream outputfile;
    string line {};
    vector <string> Constructorvalues(4);
    string CokeMachineLine{};
    bool Cline{};
    char dem = '=';
    vector <string> end;
    string input;
    int pick {};
    string IFN{};
    string OFN{};

    try
    {
        get_command_line_params(argc,argv,IFN,OFN);
    }
    catch(invalid_argument& ex)
    {
        cerr << ex.what() << endl;
        exit(0);
    }
    stringstream in (argv[1]);
    while (getline(in,input,dem))
    {
        end.push_back(input);
    }
     string inv = end.at(1);
     CokeInputFile.open(inv);
    
    
    if (CokeInputFile)
    {
        while (CokeInputFile.eof()!=1)
        {
         getline(CokeInputFile,CokeMachineLine);
         Cline = ParseCokeLine(CokeMachineLine,Constructorvalues);
            if (Cline == true)
            {
                CokeMachine tempcoke(Constructorvalues.at(0),stoi(Constructorvalues.at(1)),stoi(Constructorvalues.at(2)),stoi(Constructorvalues.at(3)));
                SetofCokeMachines.push_back(tempcoke);
            }
        }
    
    }
    else
    {
         cout << "Unable to open file"<< endl;
         exit(0);
    }
    stringstream out (argv[2]);
    vector <string> oend {};
    while (getline(out,input,dem))
    {
        oend.push_back(input);
    }
    string oinv = oend.at(1);
    outputfile.open(oinv);
    cout << "Pick a coke machine\n\n";
    do
    {
        
        cout <<"0. Exit\n";
        for (int i = 0; i < SetofCokeMachines.size(); i++)
        {
            cout << i +1 << ". "<< SetofCokeMachines.at(i).getMachineName()<< "\n";
        }
        cout << SetofCokeMachines.size()+1<< ". "<< "Add a new machine ";
        cout << "\nEnter choice ";
        cin >> pick;
        if (pick == 0)
        {
            if (outputfile)
            {
                outputfile << CreateCokeOutputLine(SetofCokeMachines);
            }
            return 0;
            
        }
        else if (pick ==SetofCokeMachines.size()+1)
        {
            CokeMachine Machine;
            SetofCokeMachines.push_back(Machine);
            MyCokeMachine = SetofCokeMachines.back();
            cout << "New machine added. "<< "\n";
        }
else
{
   do
   {

       cout << "\n\n0. Walk Away\n\n\n";
       cout << "1. Buy a Coke\n\n\n";
       cout << "2. Restock Machine\n\n\n";
       cout << "3. Add Change\n\n\n";
       cout << "4. Display Machine Info\n\n\n";
       cout << "5. Update Machine Name\n\n\n";
       cout << "6. Update Coke Price\n\n\n";
       cin >> choice;

       switch (choice)
       {
       case 0:
       cout << "\nAre you sure you aren't really THIRSTY and need a Coke"<< endl;
       break;
       

        case 1:
        cout << "\n\n\nInsert payment ";
        cin >> pay;
        check =  SetofCokeMachines.at(pick-1).buyACoke(pay,action,change);
        if (check == false )
        {
            switch (action)
            {
            case NOINVENTORY:
            cout << "test failed";
            break;
            case NOCHANGE :
            cout <<"\nUnable to give change at this time... returning your payment\n\n\n\n";
            break;
            case INSUFFCIENT:
            cout << "\n\n\nInsuffcient payment...returning your payment\n\n";
            break;
            default:
            cout << "\n\n\nChange box is full...returning your payment\n\n";
            break;

            }
        }
        else
        {
            switch (action)
            {
            case OK:
            cout << "\n\n\nHere's your coke and your change " << change <<"\n\n\n"<<endl;
            break;

            case CHANGE:
            cout << "\n\n\nThank you for exact change\n";
            cout<< "\n\n\nHere's your coke\n\n\n\n";
            break;
            
            }
        }
        break;
        case 2: 
            cout << "How much change are you adding to the machine? ";
            cin >> inventroy;
            nextcheck =  SetofCokeMachines.at(pick-1).incrementinventory(inventroy);
        if (nextcheck == true)
        {
            cout << "\n\n\nYour machine has been restocked\n"<< endl;
            cout << "Your inventory level is now "<< SetofCokeMachines.at(pick-1).getinventoryLevel()<< "\n" << endl;
        }
        else
        {
            cout << "You have exceeded your machine's max capacity\n"<< endl;
            cout <<"Your inventory level is now "<< SetofCokeMachines.at(pick-1).getinventoryLevel()<< "\n"<< endl;
        }
        break;


        case 3:
            cout<< "How much change are you adding to the machine? ";
            cin >> changeadd;
            checkchange = SetofCokeMachines.at(pick-1).incrementChangeLevel(changeadd);
        if (checkchange == true )
        {
            cout << "\n\n\nYour change has been updated\n\n"<< endl;
            cout << "Your change level is now "<< SetofCokeMachines.at(pick-1).getChangeLevel()<< endl;
            cout << "\n"<< endl;

        }
        else
        {
            cout << "You have exceeded your machine's max change capacity\n\n\n"<< endl;
            cout <<"Your change level is now "<< SetofCokeMachines.at(pick-1).getChangeLevel();

        }
        break;
        case 4:
            cout << SetofCokeMachines.at(pick-1);
            break;

        case 5 : 
            cout << "Enter a new machine name " ;
            cin.ignore(50,'\n');
            getline(cin,newmachineName);
            SetofCokeMachines.at(pick-1).setMachineName(newmachineName);
            cout << "Machine name has been updated" << endl;
            break;
        case 6:
            cout << "Enter a new coke price"<< endl;
            cin.ignore(50,'\n');
            cin >> newprice;
            SetofCokeMachines.at(pick-1).setCokePrice(newprice);
            cout << "Coke price has been updated"<< endl;
            break;
        }
        
        }while (choice != OK);
     }

  }while (pick != OK);


}


