// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
#include<algorithm>
#include<chrono> 
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;

#define INF 9999999

// number of vertices in grapj
//#define V 5

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

// int G[V][V] = {
//   {0, 9, 75, 0, 0},
//   {9, 0, 95, 19, 42},
//   {75, 95, 0, 51, 66},
//   {0, 19, 51, 0, 31},
//   {0, 42, 66, 31, 0}};

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
};

int main() {
  ifstream inFile; 
    inFile.open("check.csv");
    string line;
	int count =0;
	while(inFile.peek()!=EOF)
	{
	getline(inFile, line);
	count++;
	}
        float src[100];         
        float dest[100];
        float cost[100];

        int i=0;
        Graph g(count);
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
            g.add_edge(src[i],dest[i],cost[i]);
        } 
  int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[count];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < count - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < count; i++) {
      if (selected[i]) {
        for (int j = 0; j < count; j++) {
          if (!selected[j] && g[i][j]) {  // not in selected and there is an edge
            if (min > g[i][j]) {
              min = g[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << g[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }

  return 0;
}