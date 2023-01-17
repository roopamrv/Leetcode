#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr,int n,int i){
    int parent = i;
    int left = 2*i+1;
    int right = 2*i+2;
    

    if(left<n && arr[left] > arr[parent])
        parent = left;

    if(right <n && arr[right]>arr[parent])
            parent = right;

    if(parent != i){
        swap(arr[i],arr[parent]);
        heapify(arr,n,parent);
    }
    }
void printarray(vector<int> arr, int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
void heapbuild(vector<int> arr,int n)
{
    for(int i =((n/2)-1);i>=0;i--){
        heapify(arr,n,i);
    }
    printarray(arr,n);
    

}

void heapsort(vector<int> arr, int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    cout<<"Sorted array"<<endl;
    printarray(arr,n);
}

int main(int argc,char** argv){
    
    vector<int> arr;
    arr = {9, 6, 5, 0, 8, 2, 7, 1, 3};
    int n = arr.size();
    //int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"check n"<<n;
    heapbuild(arr,n);
    heapsort(arr,n);
    

}
