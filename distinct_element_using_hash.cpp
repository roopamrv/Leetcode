#include<stdio.h>
#include<iostream>
#include<unordered_set>
using namespace std;

int count_elements(int arr[],int n){
    unordered_set<int> s;

    for(int element = 0;element<n;element++){
        s.insert(arr[element]);

    }
    cout<<"No. of distinct elements are:"<<s.size()<<endl;
    return s.size();
}

int main(){
    int arr[] = {10,5,6,5,4,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    count_elements(arr,n);
}