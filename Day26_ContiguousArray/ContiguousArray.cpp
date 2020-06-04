// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/

// Contiguous Array


/* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000. */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int m = -1;
        int sum = 0;
        
        for (int i = 0, len = nums.size(); i < len; ++i) {
            sum += (nums[i] ? 1 : -1);
            //cout << sum << ' ';
            if (mp.find(sum) != mp.end()) {
                if (sum == 0) {
                    m = i + 1;
                }
                else {
                    m = max(m, i - mp[sum] - 1);
                }
            
            }
            else if(sum == 0) {
                m = i + 1;
            }
            mp[sum] = i;
        }
        
        
        return m;
    }
};