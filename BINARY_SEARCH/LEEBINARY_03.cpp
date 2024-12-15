#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//two pointer techinque use cheyyi
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();
    vector<pair<int, int>> jobs;  // To store (difficulty, profit)
    
    //jobs ni combine chesi vati difficulty batti sorting cheyyi
    for (int i = 0; i < n; i++) {
        jobs.push_back({difficulty[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    
    // Preprocess maximum profit for each difficulty
    vector<int> maxProfit(n);
    maxProfit[0] = jobs[0].second;  // Initialize with the first profit
    for (int i = 1; i < n; i++) {
        maxProfit[i] = max(maxProfit[i - 1], jobs[i].second);  // Cumulative max profit
    }
//  Sort workers
    sort(worker.begin(), worker.end());

 // Use two-pointer technique to calculate the maximum profit
    int totalProfit = 0, j = 0;
    for (int w : worker) {
        // Move pointer `j` to find the hardest job the worker can perform
        while (j < n && jobs[j].first <= w) {
            j++;
        }
        // Add the maximum profit the worker can earn
        if (j > 0) totalProfit += maxProfit[j - 1];
    }
    
    return totalProfit;
}

int main() {
 
    vector<int> difficulty1 = {2, 4, 6, 8, 10};
    vector<int> profit1 = {10, 20, 30, 40, 50};
    vector<int> worker1 = {4, 5, 6, 7};
    cout << "Example 1: " << maxProfitAssignment(difficulty1, profit1, worker1) << endl;  // Output: 100
     return 0;
}
