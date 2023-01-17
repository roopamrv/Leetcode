#include<stdio.h>
#include<iostream>
using namespace std;

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void intersect(int arr1[],int arr2[],int n,int m){
    int i=0,j=0;
    while (i<n && j<m){
        if(arr1[i]<arr2[j])
            i++;

        if(arr1[i]>arr2[j])
            j++;
        else
        {
            cout<<arr1[i]<<endl;
            i++;
            j++;
        }
    }
}
int main(){
    int arr1[] = {1,4,6,7,8,9};
    int arr2[] = {1,6,5,7,7,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    
    intersect(arr1,arr2,n,m);
    return 0;
}
