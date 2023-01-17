// STL implementation of Prim's algorithm for MST
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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
using namespace std;
// Class representing pair of vertex and its minEdgeCut value
// Used in minHeap in Prim's Algorithm for MST
class Element {
    public:
    int vertex;
    int minEdgeCutValue;
    Element(int v, int value) {
        vertex = v;
        minEdgeCutValue = value;
    }
};
// Class representing an edge in the graph
class Edge {
    public:
    int to;
    int weight;
    Edge(int t, int w) {
        to = t;
        weight = w;
    }
};
// Comparator to sort Element according to minEdgeCutValue
struct ElementComp {
    bool operator ()(const Element& e1, const Element& e2) {
        return (e2.minEdgeCutValue < e1.minEdgeCutValue);
    }
};
void findPrintMST(vector<Edge> graph[], int n) {
    // parent array stores the parent vertex of the current vertex in MST
    int parent[n];
    int minEdgeCut[n];
    bool includedMST[n];
    
    // Initialise all minEdgeCut values as INFINITE and all vertices as not included in MST
    for (int i = 0; i < n; i++) {
        minEdgeCut[i] = INT_MAX;
        includedMST[i] = false;
    }
    
    // Initialise minEdgeCut value of first vertex as 0
    minEdgeCut[0] = 0;
    parent[0] = -1;
    
    // Create a min heap to pick the smallest minEdgeCut value at every step
    // Min heap of vertex and corresponding minEdgeCut value
    priority_queue<Element, vector<Element>, ElementComp> minHeap;
    int min_cost =0;
    for (int i = 0; i < n; i++) {
        Element ele(i, minEdgeCut[i]);
        minHeap.push(ele);
    }
    
    // While all vertices are not included in MST
    while (minHeap.size() != 0) {
        // Select the vertex with minimum minEdgeCut value
        int u = minHeap.top().vertex;
        minHeap.pop();
        
        // Update minEdgeCut value for all adjacent vertices
        for (int j = 0; j < graph[u].size(); j++) {
            Edge curr = graph[u][j];
            // If weight of edge u-v is less than the current minEdgeCut value of v
            // update the minEdgeCut value as weight of u-v
            if (minEdgeCut[curr.to] > curr.weight && includedMST[curr.to] == false) {
                minEdgeCut[curr.to] = curr.weight;
                parent[curr.to] = u;
            }
        }
    }
    
    // Print MST
    for (int i = 1; i < n; i++) {
        cout<<parent[i]<<"----------"<<i<<" ===== "<<minEdgeCut[i]<<endl;
        min_cost +=minEdgeCut[i];
    }
    cout<< "Minimum Cost: "<< min_cost;
}
auto start = chrono::steady_clock::now();
int main() {
    vector<Edge> adj[2000];

    int size;

        //vector<vector<float>> adj[2000];
        ifstream inFile;
        unordered_set<int> s1;
        int src[2000];         //size of arrays bigger than number of entries in data file
        int dest[2000];
        int cost[2000];

        int i=0;
        inFile.open("check.csv");
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
            //cout<<src[i]<<"-----"<<dest[i]<<"------"<<cost[i]<<endl;
            s1.insert(src[i]);
           // s1.insert(dest[i]);
            vector<int> t1,t2;
            // t1.push_back(dest[i]);
            // t1.push_back(cost[i]);
            Edge e1(dest[i],cost[i]);

            adj[src[i]].push_back(e1);

            Edge e2(src[i],cost[i]);
            adj[dest[i]].push_back(e2);

        }        
        // Solution obj;
        // cout<<obj.spanningTree(i,adj)<<"\n"<<endl;
        cout<<"SIZE: "<<s1.size()<<endl;
		findPrintMST(adj,s1.size());
        
        cout<<"\nTIME TAKEN: ";
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout<< chrono::duration<double,milli>(diff).count() << "ms" <<endl;
    return 0;
}
    
    // Find MST using Prim's Algorithm and print it
    //findPrintMST(graph, 4);
    
 