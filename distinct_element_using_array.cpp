#include<stdio.h>
#include<iostream>
using namespace std;


int count_element(int arr[],int n){
    int res =0;
    for(int i = 0;i<n;i++){
        int j;
        for(j = 0;j<i;j++){
            if(arr[j]==arr[i])
                break;
        }
        if(i==j){
            res++;
        }
    }
    cout<<"Total distinct elements:" << res<<endl;
    return res;
}
int main(){
    int ar[] = {10,5,3,5,6,7,5};
    int n = sizeof(ar)/sizeof(ar[0]);
    count_element(ar,n);
}