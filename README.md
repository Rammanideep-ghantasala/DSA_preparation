/*In this you can find some important techniques and algorithms to solve some advanced problems
1.)SLIDING WINDOW TECHNIQUE:Sliding Window Technique is a method used to efficiently solve problems that involve defining a window or range in the input data (arrays or strings) and then moving that window across the data to perform some operation within the window. This technique is commonly used in algorithms like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.
How to use Sliding Window Technique?
There are basically two types of sliding window:

1. Fixed Size Sliding Window:
The general steps to solve these questions by following below steps:

Find the size of the window required, say K.
Compute the result for 1st window, i.e. include the first K elements of the data structure.
Then use a loop to slide the window by 1 and keep computing the result window by window.
2. Variable Size Sliding Window:
The general steps to solve these questions by following below steps:
In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
We follow these steps until we reach to the end of the array.*/
// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
using namespace std;

// Returns maximum sum in a subarray of size k.

int maxSum(int arr[], int n, int k)
  
{
  
    // n must be greater
  
    if (n <= k) {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

// Driver code
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}
