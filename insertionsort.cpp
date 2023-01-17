#include<stdio.h>
#include<iostream>
using namespace std;

void sort(int arr[],int n){
    for(int j=1;j<n;j++){
        int temp = arr[j];
        int i = j-1;
    while(i<j && arr[i]>temp){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1]=temp;
    }
}

void printarray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[] = {59,71,31,20,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before sort: "<<endl;
    printarray(arr,n);
    sort(arr,n);
    cout<<"Array after sort: "<<endl;
    printarray(arr,n);
    return 0;
}