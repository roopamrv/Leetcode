#include<iostream>
#include<stdio.h>
using namespace std;

void printarray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
void array_merge(int arr1[],int arr2[],int n,int m,int arr3[])
{
    int i=0,j=0,k=0;
    while (i<n && j<m){
        if(arr1[i]<arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++]; 
    }

    while(i<n)
        arr3[k++] = arr1[i++];
    
    while(j<m)
        arr3[k++] = arr2[j++];
}

int union_distinct(int arr[], int n){
    int res =0;
    for(int i=0;i<n-1;i++){
        int j;
        for(j=0;j<i;j++){
            if(arr[i]==arr[j])
            break;
        }
        if(i==j)
        res++;
    }
    cout<<"Number of distinct element in union of arrays are: "<<res<<endl;
    return res;
}
int main(){
    int arr1[] = {2,4,4,6,10};
    int arr2[] = {3,7,8,9,10};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    int arr3[n+m];
    cout<<"Array Merge: "<<endl;
    array_merge(arr1,arr2,n,m,arr3);
    printarray(arr3,(n+m));
    union_distinct(arr3,n+m);

}