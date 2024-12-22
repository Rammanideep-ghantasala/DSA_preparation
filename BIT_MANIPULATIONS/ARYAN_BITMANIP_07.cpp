#include<bits/stdc++.h>
using namespace std;
/* problem: you are given N64 bit integrs such that two successive numbers
differ at exactly 1bit.your job is to find out if there are 4 integers such that
their XOR is equal to 0
GRAY CODE+Some extra operation we should 
*/
bool hasFourIntegersWithXORZero(const vector<int64_t>& nums) {
    unordered_map<int64_t, pair<int, int>> xorPairs;
    int n = nums.size();
  
    // Iterate over all pairs of numbers
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int64_t xorValue = nums[i] ^ nums[j];

            // Check if this XOR value already exists
            if (xorPairs.find(xorValue) != xorPairs.end()) {
                auto [p1, p2] = xorPairs[xorValue];
                // Ensure indices are distinct
                if (p1 != i && p1 != j && p2 != i && p2 != j) {
                 return true;
                }
            } else {
                // Store the pair
                xorPairs[xorValue] = {i, j};
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (hasFourIntegersWithXORZero(nums)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}


