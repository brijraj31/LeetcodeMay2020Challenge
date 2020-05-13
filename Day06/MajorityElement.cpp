// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/

/* Majority Element
 */

/* Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2 */


class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int ans = INT_MAX;
        int count = 0;
        int size = arr.size();
        for(int i = 0; i < size; ++i) {
            if(arr[i] == ans) {
                count ++;
            }
            else if(count == 0) {
                ans = arr[i];
                count ++;
            }
            else {
                count--;
            }
        }

        int check = 0;
        for(int i = 0; i < size; ++i) {
            if(arr[i] == ans) {
                check++;
            }
        }

        if(check > (size >> 1)) {
            return ans;
        }
        else return -1;
    }
};