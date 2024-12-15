/*You are given a 0-indexed integer array nums and an integer x.

Find the minimum absolute difference between two elements in the array that are at least x indices apart.

In other words, find two indices i and j such that abs(i - j) >= x and abs(nums[i] - nums[j]) is minimized.

Return an integer denoting the minimum absolute difference between two elements that are at least x indices apart.

Example 1:
Input: nums = [4,3,2,4], x = 2
Output: 0
Explanation: We can select nums[0] = 4 and nums[3] = 4. 
They are at least 2 indices apart, and their absolute difference is the minimum, 0. 
It can be shown that 0 is the optimal answer.
*/
#include<bits/stdc++.h>
using namespace std;

int minabsoluteDifference(vector<int>& nums, int x) {
    int n = nums.size();
    set<int> window;  // Stores elements in sorted order.ikkada sets use chesam so,sets will store in sorted order
    int minDiff = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Remove elements that are no longer at least x apart
        if (i >= x) {
            window.insert(nums[i - x]);  
            // Add the previous valid index value into the set
        }

        if (!window.empty()) {
            // Binary search for closest element >= nums[i]
            auto it = window.lower_bound(nums[i]);
            if (it != window.end()) {
                minDiff = min(minDiff, abs(*it - nums[i]));
            }

            // Binary search for closest element < nums[i]
            if (it != window.begin()) {
                it--;
                minDiff = min(minDiff, abs(*it - nums[i]));
            }
        }
    }

    return minDiff;
}

int main() {
    vector<int> v ;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int x1 = 2;
    cout << "Example 1: " << minabsoluteDifference(v, x1) << endl;  

    return 0;
}
