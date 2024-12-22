#include<bits/stdc++.h>
using namespace std;
/*Given an array of integers, find all unique numbers
 and print them in ascending order.*/
 void finduniquenumbers(vector<int>n){
    unordered_map<int,int>frequencymap;
    for(int num: n){
        frequencymap[num]++;

    }
    vector<int>uniquenumbers;
    for(auto it:frequencymap){
        if(it.second==1){
            uniquenumbers.push_back(it.first);
        }
    }
    sort(uniquenumbers.begin(),uniquenumbers.end());
    for(int value :uniquenumbers){
        cout<<value<<" ";
    }
    cout<<endl;
 }
 int main(){
    vector<int>v;
    int n;
    cout<<"enter the no : elements";
    cin>>n;
    cout<<"enter the integers"<<endl;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"unique numbers in the array are";
    finduniquenumbers(v);
    return 0;
 }
 /*
 Explanation
Input Array: The nums vector contains integers.
Frequency Map: unordered_map<int, int> stores the frequency of each number in the array.
Filter Unique Numbers: Numbers with a frequency of 1 are added to the uniqueNumbers vector.
Sorting: std::sort ensures the unique numbers are printed in ascending order.
Output: The unique numbers are printed to the console
 */