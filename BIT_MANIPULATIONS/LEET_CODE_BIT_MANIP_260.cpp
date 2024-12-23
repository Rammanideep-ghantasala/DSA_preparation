/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long result=0 ;
        for(int num:nums){
            result^=num;
        }
        //upto here we can find only one unique number if the array has one unique number
        //but in this prblm u have two unique numbers 
        //INT_MIN integer loo represent loo cheyalem andukee long vadu
        long long diffBit = result & -result;

    // Step 3: Partition numbers based on the diffBit
    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & diffBit) {
            num1 ^= num; // Group where diffBit is set
        } else {
            num2 ^= num; // Group where diffBit is not set
        }
    }

    return {num1, num2};
}
   