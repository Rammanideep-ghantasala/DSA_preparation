#include <bits/stdc++.h>
using namespace std;
// is valid loo greedy technique use cheyyi
bool isValid(vector<int> &start, int d, int n, int mid) {
    int prev = start[0]; // Pick the smallest possible value in the first range
    for (int i = 1; i < n; i++) {
        int lowerBound = prev + mid;  //  difference should bee at least 'mid'
        int next = max(start[i], lowerBound); // Choose the smallest valid number >= lowerBound
        if (next > start[i] + d) return false; // If it's out of the range, return false
        prev = next; // Update previous chosen value
    }
    return true;
}
//maximum kanukovadainiki binary search use cheyyi
int maximizeScore(vector<int> &start, int d) {
    int n = start.size();
    sort(start.begin(), start.end()); // Sort the intervals by their starting points

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
