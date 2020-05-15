// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

/* Ransom Note */

/* Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters. */


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freqRan[26];
        int freqMaz[26];
        memset(freqRan, -1, 26 * sizeof(int));
        memset(freqMaz, -1, 26 * sizeof(int));
        
        for(int i = 0, len = ransomNote.size(); i < len; ++i) {
            freqRan[ransomNote[i] - 'a'] ++;
        }
        for(int i = 0, len = magazine.size(); i < len; ++i) {
            freqMaz[magazine[i] - 'a'] ++;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (freqMaz[i] < freqRan[i]) return false;
        }
        return true;
    }
};