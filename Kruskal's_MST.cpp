//Implementation of Kruskal's algorithm

#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<chrono> 
#include <fstream>
#include <string>
#include <sstream>
#include<unordered_set>

using namespace std;
//performing disjoint set and unioin data structure
//rank by unioin and path compression

class DisjointSetUnion{
    int* parent;
    int* rank;

public:
    DisjointSetUnion(int n){
        parent = new int[n];
        rank = new int[n];

        for (int i =0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    //finding parent function
    int findfunc(int x){
        if(parent[x]==-1)
            return x;
        
        return parent[x] = findfunc(parent[x]);
    }

    //union funtion 
    void unionfunc(int x,int y){
        int x1 = findfunc(x);
        int y2 = findfunc(y);

        if(x1 != y2)
        {
            if(rank[x1]<rank[y2]){
                parent[x1] = y2;
                rank[y2] += rank[x1];
            }
            else{
                parent[y2] = x1;
                rank[x1] += rank[y2];
            }
        }
    }
};

class Graph
{
    vector<vector<float>> adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;}
    

    void add_edge(float x,float y,float w){
        adj.push_back({w,x,y});
    }

    void spanningTree()
    {
        sort(adj.begin(),adj.end());

        DisjointSetUnion s(V);
        int min_cost =0;

        cout<<"-----Path with minimum cost-----"<<endl;
        for( auto it: adj){
            int w = it[0];
            int x = it[1];
            int y = it[2];
        

        if(s.findfunc(x) != s.findfunc(y)){
            s.unionfunc(x,y);
            min_cost += w;
        
            cout<<x<<"--------"<<y<<"==="<<w<<endl;
        }
        }
    cout << "Minimum cost of spanning tree: "<<min_cost<<endl;
    
    }
};


auto start = chrono::steady_clock::now();
int main(){
    int size;

        ifstream inFile; 
        float src[INT8_MAX];         
        float dest[INT8_MAX];
        float cost[INT8_MAX];

        int i=0;
        Graph g(INT8_MAX);
        inFile.open("DATASET-100.csv");
        unordered_set<int> s1;

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
            g.add_edge(src[i],dest[i],cost[i]);
            
            s1.insert(src[i]);
            s1.insert(dest[i]);
        }
        
        g.spanningTree();
        
        cout<< "Number of nodes:"<<s1.size()<<endl;
        cout<<"TIME TAKEN: ";
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout<< chrono::duration<double,milli>(diff).count() << "ms" <<endl;
    return 0;
}
