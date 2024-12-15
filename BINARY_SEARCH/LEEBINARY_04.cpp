/*You are given an array of integers start and an integer d, representing n intervals [start[i], start[i] + d].

You are asked to choose n integers where the ith integer must belong to the ith interval. The score of the chosen integers is defined as the minimum absolute difference between any two integers that have been chosen.

Return the maximum possible score of the chosen integers.
Example 1:

Input: start = [6,0,3], d = 2

Output: 4

Explanation:

The maximum possible score can be obtained by choosing integers: 8, 0, and 4. The score of these chosen integers is min(|8 - 0|, |8 - 4|, |0 - 4|) which equals 4.

Example 2:

Input: start = [2,6,13,13], d = 5

Output: 5

Explanation:

The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. The score of these chosen integers is min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) which equals 5.
*/



#include <bits/stdc++.h>
using namespace std;
// is valid loo greedy technique use cheyyi
bool isValid(vector<int> &start, int d, int n, int mid) {
    int prev = start[0]; // Pick the smallest possible value in the first range
    for (int i = 1; i < n; i++) {
        int lowerBound = prev + mid;            //  difference should bee at least 'mid'
        int next = max(start[i], lowerBound);     // choose the smallest valid number >= lowerBound
        if (next > start[i] + d) return false;     // if out of the range, return false
        prev = next; // Update previous chosen value
    }
    return true;
}
//maximum kanukovadainiki binary search use cheyyi
int maximizeScore(vector<int> &start, int d) {
    int n = start.size();
    sort(start.begin(), start.end()); // sort the intervals by their starting points

    int low = 0, high = d, ans = 0;

    // binary search on the minimum score
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isValid(start, d, n, mid)) {
            ans = mid;  // update answer
            low = mid + 1; // try for  larger minimum score
        } else {
            high = mid - 1; //reduce score
        }
    }
    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> start(n);
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << maximizeScore(start, d) << endl;
    return 0;
}
