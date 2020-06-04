// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/

// Permutation in String


/* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000]. */


class Solution {
  public:
    bool checkInclusion(string p, string s) {
      if (s.length() < p.length()) return false;
      int l1 = s.length();
      int l2 = p.length();
      vector < int > cnt(26, 0);
      for (int i = 0; i < l2; ++i) {
        cnt[s[i] - 'a']++;
        cnt[p[i] - 'a']--;
      }
      for (int i = l2; i < l1; ++i) {
        if (all_of(cnt.begin(), cnt.end(), [](int i) {
            return i == 0;
          })) {
            return true;
          //cout << "Yeah \n";
        }
        // for (int j = 0; j < 26; ++j) {
        //   cout << cnt[j] << " ";
        // }
        // cout << '\n';
        cnt[s[i] - 'a']++;
        cnt[s[i - l2] - 'a']--;
      }
      if (all_of(cnt.begin(), cnt.end(), [](int i) {
          return i == 0;
        })) {
        return true;
      }
      return false;
    }
};