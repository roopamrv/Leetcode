#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <chrono>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <limits.h>


using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle

        
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

auto start = chrono::steady_clock::now();
int main()
{
    int minimumCost;
    ifstream inFile;

        int src[INT8_MAX];         
        int dest[INT8_MAX];
        int cost[INT8_MAX];

        int i=0;
        inFile.open("DATASET-100.csv");

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
			adj[src[i]].push_back(make_pair(cost[i], dest[i]));
            adj[dest[i]].push_back(make_pair(cost[i], src[i]));
            //addEdge(graph,src[i],dest[i],cost[i]);
        }




    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;

            
    cout<<"TIME TAKEN: ";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<< chrono::duration<double,milli>(diff).count() << "ms" <<endl;
    return 0;
}