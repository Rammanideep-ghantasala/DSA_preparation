/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/
class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int temp=a^b;//see by doing xor u will get the addition for diff bits
            b=((a&b)<<1);//by this you will get carry and shift this to left
            a=temp;
        }
        return a;
    }
};