// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

// Count Square Submatrices with All Ones


/* Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1 */


class Solution {
int dp[302][302];
public:
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int count = 0;
        
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= m; ++j) {
              if (matrix[i - 1][j - 1]) {
                  int edgeSize = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                  count = count + (edgeSize);
                  dp[i][j] = edgeSize;
              }
          }  
        }
        
        return count;
    }
};