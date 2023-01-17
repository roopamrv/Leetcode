#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int mincost(vector<int> &vect){
    
    //priority_queue<int,vector<int>,greater<int>> minheap(vect,vect+n);
    priority_queue<int> pq;
    for(auto &i:vect){
        pq.push(-i);
    }
  int ans = 0;
    
    while(pq.size()>1){
        int sum =0;
        int first = -pq.top();
        pq.pop();
        int second = -pq.top();
        pq.pop();

        sum = first+second;
        ans= ans+sum;
        
        pq.push(-sum);
    }
    cout << ans << endl;
    return ans;
}

int main(){
    vector<int> vect{2,5,4,8,6,9};
    mincost(vect);
}