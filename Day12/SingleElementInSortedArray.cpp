// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th

/* Single Element in a Sorted Array
 */

/* You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space. */


// O(n) solution 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int elem = 0;
        
        for (int i = 0, len = nums.size(); i < len; ++i) {
            elem = elem ^ nums[i];
        }
        
        return elem;
    }
};
