#include<bits/stdc++.h>
using namespace std;
/*  
Key Insight
The condition 
𝑎[𝑖]&𝑎[𝑗]≥𝑎[𝑖]⊕𝑎[𝑗]
a[i]&a[j]≥a[i]⊕a[j] can be simplified using properties of binary numbers:

The most significant bit (MSB) of two numbers largely determines whether the condition holds.
If two numbers share the same MSB position, then the condition is guaranteed to be true
*/
/*You are given an array of integers, and you need to count the number of valid pairs 
(𝑖,𝑗)
(i,j) such that:
1≤𝑖<𝑗≤𝑛
1≤i<j≤n,
𝑎[𝑖]&𝑎[𝑗]≥𝑎[𝑖]⊕𝑎[𝑗]
a[i]&a[j]≥a[i]⊕a[j].
Here, && is the bitwise AND, and ⊕
⊕ is the bitwise XOR operation.*/
 int getmsb(int num){
    int msb=0;
    while(num>0){
        num>>=1;
        msb++;
    }
    return msb;
 }
 void solve(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    unordered_map<int,int>msbcount;
    for(int num : v){
        int msb=getmsb(num);
        msbcount[msb]++;

    }
    long totalpairs=0;
    for(auto [msb,count]: msbcount){
        if(count>1){
            totalpairs+=1LL*count*(count-1);
        }
    }
    cout<<totalpairs<<endl;
 }
 int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
 }
 /*
 Time Complexity:
Calculating MSB for each number: 
𝑂(log(max(𝑎[𝑖]))⋅𝑛)
O(log(max(a[i]))⋅n).
Counting pairs for each group: 
𝑂(number of groups)
O(number of groups), which is negligible.
Overall: Approximately 
𝑂(𝑛⋅log(max(𝑎[𝑖])))
O(n⋅log(max(a[i]))).
Space Complexity:
Storage for unordered_map: 
𝑂(number of groups)
O(number of groups),
 which is proportional to the number of unique MSB positions.
 */
/*EXPLANATION
Explanation of the Code
MSB Calculation: The getMSB function calculates the most significant bit position of a number using repeated right shifts.
Grouping by MSB: Numbers are grouped using an unordered_map where the key is the MSB position, and the value is the count of numbers with that MSB.
Counting Pairs: For each group, the total number of valid pairs is computed using 
𝐶(𝑘,2)
C(k,2).
Iterate for Multiple Test Cases: The main function handles multiple test cases.

*/