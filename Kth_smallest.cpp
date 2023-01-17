#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;


//to implement minheap use- priority_queue<int,<vector<int>,greater<int>> minheap;

void Ksmallest(vector<int> &arr,int n,int k){
    priority_queue<int> pq;
    for(auto &i: arr){
        pq.push(-i);
    }

    for(int i=1;i<k;i++){
        pq.pop();
    }
    cout<<-pq.top()<<endl;
}

int main(){
    vector<int> arr{10,20,40,60,8,9,4};
    int n = arr.size();
    int k = 3;

    Ksmallest(arr,n,k);
}