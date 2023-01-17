#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        if(min!=i){
            swap(arr[i],arr[min]);
            // int temp = arr[i];
            // arr[i] = arr[min];
            // arr[min] = temp;
        }
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[] = {2,1,4,3,8,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sort: "<<endl;
    printarray(arr,n);
    sort(arr,n);
    cout<<"Array after sort: "<<endl;
    printarray(arr,n);
}