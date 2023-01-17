#include<iostream>
#include<stdio.h>
#include<unordered_map>
using namespace std;

void subarray(int arr[],int n,int sum){
    unordered_map<int,int> mp;
    int curr_sum = 0;
    int start =0;
    int end =-1;

    for(int i =0;i<n-1;i++){
        curr_sum += arr[i];

        if(curr_sum - sum == 0){
            start =0;
            end =i;
        }

        if(mp.count(curr_sum-sum)==1){
            start = mp[curr_sum-sum] +1;
            end =i;
        }
        mp.insert({curr_sum,i});
    }

    if(end == -1){
        cout<< "sum not found in subarray"<<endl;
    }
    else
        cout<<"START: "<<start<<" "<<"END: "<<end<<endl; 
}

int main(){
    int arr[] = {10,5,6,20,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 26;

    subarray(arr,n,sum);
}