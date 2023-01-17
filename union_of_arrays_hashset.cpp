#include<iostream>
#include<stdio.h>
#include<unordered_set>
using namespace std;

int union_hash(int arr1[],int arr2[],int n,int m)
{
    unordered_set<int> s;
    
    for(int el = 0;el<n;el++){
        s.insert(arr1[el]);
    }
    for(int i =0;i<m;i++)
    {
        s.insert(arr2[i]);
    }

    cout<<"No of distinct element in union of both arrays: "<<s.size()<<endl;
    return s.size();
}

int main(){
    int arr1[] = {2,3,6,5,5,6};
    int arr2[] = {2,5,6,7,8};

    int n= sizeof(arr1)/sizeof(arr1[0]);
    int m= sizeof(arr2)/sizeof(arr2[0]);

    union_hash(arr1,arr2,n,m);
}
