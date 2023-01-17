//Implementation of Prim's Algorithm for MST

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<chrono>
#include <sstream>
#include <vector>
#include <fstream>
#include<algorithm>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct pair1{
    bool operator() (pair<float,float> &p1,pair<float,float> &p2){
        return (p1.second<p2.second);
    }
};

class Solution: pair1 {
    public: 
    int spanningTree(int v,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    unordered_set<int> visited;

    float cost =0;
    
    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();
        //cout<<"u.first: "<<u.first<<"u.second: "<<u.second<<endl;
        int node = u.second;
        if(visited.count(node)) continue;
        visited.insert(node);
        cost += node;

        for(auto v: adj[int(node)]){
            float neighbor = v[0];
            if(visited.count(neighbor)) continue;
            pq.push({v[1],v[0]});
        }
    }
    cout<<"Size: "<<pq.size()<<endl;
    cout<< "Minimum Cost: ";
    return cost;
    }
};
auto start = chrono::steady_clock::now();
int main(){
    int size;

        vector<vector<int>> adj[2000];
        ifstream inFile; 
        int src[2000];         //size of arrays bigger than number of entries in data file
        int dest[2000];
        int cost[2000];

        int i=0;
        inFile.open("DATAFILE.csv");
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
            cout<<src[i]<<"-----"<<dest[i]<<"------"<<cost[i]<<endl;
            vector<int> t1,t2;
            t1.push_back(dest[i]);
            t1.push_back(cost[i]);
            //for(int i=0;i<t1.size();i++) cout<<"t1 is: "<<t1[i]<<endl;
            adj[src[i]].push_back(t1);
            t2.push_back(src[i]);
            t2.push_back(cost[i]);
            //for(int i=0;i<t2.size();i++) cout<<"t2 is: "<<t2[i]<<endl;
            adj[dest[i]].push_back(t2);
        }        
        Solution obj;
        cout<<obj.spanningTree(i,adj)<<"\n"<<endl;

        
        cout<<"TIME TAKEN: ";
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout<< chrono::duration<double,milli>(diff).count() << "ms" <<endl;
    return 0;
}



