#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr,int l,int h)
{
    int i = l;
    int j = h;
    int pivot = arr[l];

    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[l],arr[j]);
    return j;
}

void quicksort(vector<int>& arr,int l,int h){
    if(l<h){
    int pivot= partition(arr,l,h);

    quicksort(arr,l,pivot-1);
    quicksort(arr,pivot+1,h);
    }
}
void printarray(vector<int> arr,int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(int argc,char **argv){
    vector<int> arr{4,6,2,5,7,1,9,3};

    int n= arr.size();
    cout <<"checking n "<<n<<endl;
    cout<<"Array before sort:"<<endl;
    printarray(arr,n);
    quicksort(arr,0,n-1);
    cout<<"Array after sort"<<endl;
    printarray(arr,n);

}