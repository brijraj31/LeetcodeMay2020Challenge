// Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/

// Edit Distance

/* Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u') */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp;
        for (int i = 0; i <= word1.length(); ++i) {
            vector<int> temp(word2.length() + 1, 0);
            dp.push_back(temp);
        }
        
        
        
        for (int i = 0; i <= word1.length(); ++i) {
            for (int j = 0; j <= word2.length(); ++j) {
                if(i == 0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = i;
                    continue;
                }
                
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                                                                      
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};


int main() {


    string word1 = "", word2 = "a";

    Solution s;
    cout << s.minDistance(word1, word2);


    return 0;
}