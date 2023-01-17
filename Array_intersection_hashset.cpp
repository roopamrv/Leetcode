#include<stdio.h>
#include<iostream>
#include<unordered_set>
using namespace std;

int intersect(int arr1[],int arr2[],int n,int m){
    unordered_set<int> s;
    int count =0;
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }

    for(int j=0;j<m;j++){
        if(s.count(arr2[j])==1){
                count++;
                s.erase(arr2[j]);
        }
    }
    cout<<"No of Intersected elements: " <<count<<endl;
    cout<<"Unique elements: "<<endl;
    for(auto it:s){
        cout<<it<<endl;
    }
    return count;
}

int main(){
    int arr1[] = {1,4,6,7,8,9};
    int arr2[] = {1,6,5,7,7,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    intersect(arr1,arr2,n,m);
}