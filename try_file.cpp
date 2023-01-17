#include <fstream>
#include <iostream>
#include <string>
using namespace std;

 int main()
 {

 ifstream inFile; 

 int src[100];         //size of arrays bigger than number of entries in data file
 int dest[100];
 int cost[100];

 int i=0;
inFile.open("data.csv");
if (inFile.fail())
{
    cout << "Error" << endl;
    return 1;
}
while (!inFile.eof())
{
    inFile >> src[i];
    inFile >> dest[i];
    inFile >> cost[i];

       

    cout << cost[i] << endl; 
    i++; // display values in the array to check that the correct values have been imported                                             
}
inFile.close();

return 0;

 }
