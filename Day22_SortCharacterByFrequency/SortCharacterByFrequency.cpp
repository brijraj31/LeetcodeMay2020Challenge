// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/

// Sort Characters By Frequency


/* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters. */


class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128,0);
        
        for (auto ch: s) {
            freq[ch - ' ']++;
        }
        
        sort(s.begin(), s.end(), [&] (const char a, const char b) {
            if (freq[a - ' '] != freq[b - ' ']) {
                return freq[a - ' '] > freq[b - ' '];
            }
            else {
                return a > b;
            }
        });
        
        return s;
    }
};