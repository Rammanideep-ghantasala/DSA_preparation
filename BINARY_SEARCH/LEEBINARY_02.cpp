/*A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
*/
#include<bits/stdc++.h>
using namespace std;

////sliding window use cheyyi
int maxConsecutiveAnswers(string answerKey, int k) {//this is function for calculating maxconsecutiveansers
    int n = answerKey.size();
    return max(maxConsecutive(answerKey, k, 'T'), maxConsecutive(answerKey, k, 'F'));
}
// Helper function to calculate max window size for target character
int maxConsecutive(const string &s, int k, char target) {
    int l = 0, r = 0, maxLength = 0, flips = 0;

    while (r < s.size()) {
        if (s[r] != target) {
            flips++;  // Count a flip if current character is not target
        }

        // If flips exceed k, shrink the window
        while (flips > k) {
            if (s[l] != target) {
                flips--;
            }
            l++;
        }

        // Update the maximum window size
        maxLength = max(maxLength, r - l + 1);
        r++;
    }

    return maxLength;
}

int main() {
    string answerKey1 = "TTFF";
    int k1 = 2;
    cout << "Example 1: " << maxConsecutiveAnswers(answerKey1, k1) << endl;  // Output: 4
    return 0;
}
