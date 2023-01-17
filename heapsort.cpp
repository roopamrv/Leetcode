#include <iostream>
#include <vector>
#include<stdio.h>

using namespace std;


    void printarray(vector<int> arr,int n){
        for(int i =0;i<n; ++i){
            cout<<arr[i]<<endl;
        }
    }
    void heapify(vector<int>& arr,int n, int i){
       
        int parent = i;
        int left = ((2*i)+1);
        int right = ((2*i)+2); 
        

        if(left < n && arr[left] > arr[parent]){
            parent = left;
        }

        if(right < n && arr[right]> arr[parent]){
            parent = right;
        }

        if(parent != i){
            swap(arr[i],arr[parent]);
            heapify(arr,n,parent);
        }
        
    }
    void heapbuild(vector<int> arr, int n){
        for(int i = ((n/2)-1);i>=0;i--){
            heapify(arr,n,i);
        }
        cout<<"sorted array"<<endl;

        for(int i=n-1;i>0;i--){
           swap(arr[0],arr[i]);

            
            cout<<"checking" << arr[1]<< endl;
            heapify(arr,i,0);
            
        }
        cout<<"heap sort "<<endl;
        printarray(arr,n);
        // for(int i = n-1;i>0;i--){
        //     swap(arr[0],arr[i]);
        //     heapify(arr,i,0);
        // }
    }


    int main(int argc,char **agrv){
        vector<int> arr;
        arr = {50,45,60,30,20,35,10};
        
        
        int n= sizeof(arr)/sizeof(arr[0]);
        heapbuild(arr,n);
        
        //heapsort(arr,n);
        // cout<< "sorted array"<<endl;
        // printarray(arr,n);
        return 0;
    }
