#include <iostream>
#include <string>
#include <iomanip> //used for formatting outputs
// <iostream> means look in standard directory where all libraries are
//in header files, can do things like include
// then in main program, write include "headerfilename.h"
//the string stream library
#include <sstream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std; 

int main() 
{

	// define variables
	string src, dest, wt; //variables from file are here
	vector<int>SRC;
	vector<int>DEST;
	vector<int>WT;


	//number of lines
	int i = 0;

	ifstream coeff("data.csv"); //opening the file.
	if (coeff.is_open()) //if the file is open
	{
		//ignore first line
		string line;
		vector<int> val;
		vector<vector<int>> adj[i];
		getline(coeff, line);

		while (!coeff.eof()) //while the end of file is NOT reached
		{
			//I have 3 sets {SRC,DEST,WT} so use 3 getlines
			// getline(coeff, dest, ',');
			// SRC.push_back(stoi(dest));
			// getline(coeff, wt,'\n');
			// WT.push_back(stoi(wt));
			// adj[stoi(src)].push_back(WT);

			// getline(coeff, src, ',');
			// SRC.push_back(stoi(src));
			// getline(coeff, wt,'\n');
			// WT.push_back(stoi(wt));
			// adj[stoi(dest)].push_back(WT);
			vector<int> t1,t2;
			getline(coeff, src, '\n');
			
			t1.push_back(stoi(src));
			cout<<t1[i]<<endl;
			
			
			i += 1; //increment number of lines
		}

		coeff.close(); //closing the file
		cout << "Number of entries: " << i-1 << endl;
		for(int x =0;x<i;x++){
		//cout<<SRC[x]<<" "<<DEST[x]<<" "<<WT[x]<<endl;
		}
	}
	else cout << "Unable to open file"; //if the file is not open output
}
	//output values and find CD0, CY0, CL0
// 	cout << "AOA" << "\t" << "CD" << "\t" << "CL" << "\t" << "CY" << endl;
// 	float CDO, CLO, CYO;
// 	for (int j = 0; j < i; j++) {
// 		cout << AoA[j] << "\t" << C_D[j] << "\t" << C_L[j] << "\t" << C_Y[j] << endl;
// 		if (AoA[j] == 0) {
// 			CDO = C_D[j];
// 			CLO = C_L[j];
// 			CYO = C_Y[j];
// 		}
// 	}
// 	cout << endl;
// 	cout << "At zero AoA, CD = " << CDO << ", CL = " << CLO << ",and CY = " << CYO << endl;
//     return 0;
// }