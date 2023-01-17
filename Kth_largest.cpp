#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

void Klargest(vector<int> &arr, int n, int k){
    priority_queue<int> pq;
    for(auto &i: arr){
        pq.push(i);
    }

    for(int i =1;i<k;i++){
        pq.pop();
    }

    cout<<pq.top()<<endl;
}

int main(){
    vector<int> vect{10,30,20,50,2};
    int n = vect.size();
    int k = 3;
    Klargest(vect,n,k);

}