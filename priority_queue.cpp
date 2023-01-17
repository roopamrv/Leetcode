//K-th largest Number

#include<queue>
#include<stdio.h>
#include<iostream>

using namespace std;

void priority(priority_queue<int> pq){
    
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
}

int main(){
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(20);
    pq.push(8);
    int k =2;

    priority(pq);
}