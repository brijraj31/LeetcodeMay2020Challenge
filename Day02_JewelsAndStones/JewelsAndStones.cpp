// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

/* Jewels and Stones */

/* You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Above line are not required in the code submission


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<int> s; 
        for (char x : J) {
            s.insert(x);
        }
        int count = 0;
        for(char x : S) {
            if(s.find(x) != s.end())
                count ++;
        }
        return count;
    }
};


int main() {


    string J, S;

    cin >> J >> S;

    Solution sol;
    cout << sol.numJewelsInStones(J, S);
    
    return 0;

}