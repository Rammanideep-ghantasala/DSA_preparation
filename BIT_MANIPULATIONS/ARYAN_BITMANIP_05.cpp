/*#include<bits/stdc++.h>
using namespace std;
int finduniquenumbers(vector<int>nums){
    int unique=0;
    for(int value :nums){
        unique^=value;
    }
    return unique;
}
int main(){
    vector<int>v;
    int n;
    cout<<"enter the vlaue of n";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"the unique elements in the given array is "<<finduniquenumbers(v)<<endl;
    return 0;
}*/
#include <iostream>
#include <vector>

int findUniqueNumber(const std::vector<int>& nums) {
    int unique = 0;

    // XOR all elements in the array
    for (int num : nums) {
        unique ^= num;
    }

    return unique;
}

int main() {
    std::vector<int> nums = {4, -5, 6, 4, 6}; // Example input with one unique negative number
    std::cout << "The unique number is: " << findUniqueNumber(nums) << std::endl;

    return 0;
}
