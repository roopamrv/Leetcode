#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int left;
	int right;
	int mid;

public:
    int search(vector<int> nums, int target) {
    	left =0;
    	right = nums.size()-1;
        cout << left<< " "<< right << endl;
        while(left <= right)
        {
            mid = left +(right-left)/2;
            cout << mid << endl;
            if(target == nums[mid]){
                cout << "in the middle: " << mid<<endl;
                return mid;
            }
            if (target < nums[mid])
                right = mid -1;
            if (target > nums[mid])
             left = mid + 1;
        }
        cout << "finally found" << -1;
    return -1;
    }

};



int main(int argc, char *argv[]){
    Solution s;
    int arr[] = { 1,2,3,4,5,6,7,8};
    int a;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    int tar = 7;
    a = s.search(vect,tar);
    if (a==-1) cout << "Element not found";
    else cout<<"Element fornd at index : "<<a<<endl;
    //cout <<ans<<endl;
    return 0;
}


