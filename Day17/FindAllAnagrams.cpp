// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/

// Find All Anagrams in a String


/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

using namespace std;
class Solution {
  public: vector < int > findAnagrams(string s, string p) {
    vector < int > ans;
    if (s.length() < p.length()) return ans;
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
        ans.push_back(i - l2);
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
      ans.push_back(l1 - l2);
    }
    return ans;
  }
};