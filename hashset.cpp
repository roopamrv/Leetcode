#include<stdio.h>
#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(6);

    cout<<"Set Count function: "<<s.count(10)<<endl;
    auto pos = s.find(10);
    cout<<"Set Find function (Position of 10): ";
    cout<<*pos<<endl;

    if(s.count(10))
    cout<<"10 is present "<<endl;

    s.erase(10);
    for( auto i: s){
        cout<<i<<endl;
    }
    
    s.erase(s.begin(),s.end());
    cout<<s.size()<<endl;
    
}