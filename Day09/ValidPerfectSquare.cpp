// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/

/* Valid Perfect Square
 */

/* Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false */


class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;
        
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            long long int sq = (long long int)mid * mid;
            if (sq == num) return true;
            
            else if (sq < num) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};

