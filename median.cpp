#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;


priority_queue<int> maxheap;
priority_queue<int,vector<int>,greater<int>> minheap;

void insert_num(int num){
    
    if(maxheap.empty() || maxheap.top()>=num)
        maxheap.push(num);

    else
        minheap.push(num);

    //checking if maxheap and minheap are of same size or maxheap is greater that minheap in case of odd number of input

    if(maxheap.size() > minheap.size()+1){
        minheap.push(maxheap.top());
        maxheap.pop();
    }

    if(maxheap.size()<minheap.size()){
        maxheap.push(minheap.top());
        minheap.pop();
    }

}

double find_median(){
    if(maxheap.size() == minheap.size()){
        return ((maxheap.top()+minheap.top())/2);
    }
    else
        return maxheap.top();
}



int main(){
    insert_num(3);
    insert_num(1);
    cout<<"Median of 1 and 3: "<<find_median()<<endl;

    insert_num(5);
    cout<<"Median of 1,3 and 5: "<<find_median()<<endl;

    insert_num(7);
    cout<<"Median of 1,3,5 and 7: "<<find_median()<<endl;
    return 0;
}