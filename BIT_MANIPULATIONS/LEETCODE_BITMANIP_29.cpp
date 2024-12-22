/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2*/
class Solution {
public:
    int divide(int dividend, int divisor) {
           bool negative = (dividend < 0) ^ (divisor < 0); // XOR for opposite sign
            if(divisor==0){
              return false;
            }
            if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // Maximum 32-bit integer
    }
    long quotient=0;
    long long absdividend=abs((long long)dividend);
    long long absdivisor=abs((long long)divisor);
    while(absdividend>=absdivisor){
           int multiple=1;
           long long currentdivisor=absdivisor;
        while (absdividend >= (currentdivisor << 1)) {
            currentdivisor <<= 1;
            multiple <<= 1;
        }
        // Subtract the current divisor from the dividend and add the multiple to the quotient
        absdividend -= currentdivisor;
        quotient += multiple;
    }
    
    return negative ? -quotient : quotient;
    }

    
};