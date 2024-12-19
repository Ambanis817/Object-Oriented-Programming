#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include<map>

using namespace std;

int main (int agrc,char *argv[])
{
    string filename = argv[1];
    ifstream filehandle;
    string fileline;
    map<string,int>mymap;

    while(getline(fileline,filename))
    {
        mymap[fileline]++;
    }
    filehandle.close();

    return 0;

}


