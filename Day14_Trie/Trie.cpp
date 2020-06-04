// Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/ */

/* Implement Trie (Prefix Tree)
Solution
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings. 

*/
#include <bits/stdc++.h>

using namespace std;

class Trie {
    class TrieNode {
        public :
        bool isLeaf;
        unordered_map<char, TrieNode*> children;
        TrieNode() {
            isLeaf = false;
        }
        TrieNode(const char c) {
            children[c] = new TrieNode();
            isLeaf = false;
        }
    };

    TrieNode* root;

    TrieNode* searchNode(const string& word) {
        TrieNode* temp = root;

        for (int i = 0, len = word.length(); i < len; ++i) {
            const char c = word[i];

            if (temp -> children.find(c) != temp -> children.end()) {
                temp = temp -> children[c];
            }
            else return nullptr;
        }

        return temp;
    }
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root =  new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0, len = word.length(); i < len; ++i) {
            char c = word[i];

            if (temp -> children.find(c) == temp -> children.end()) {
                temp -> children[c] = new TrieNode();
            }

            temp = temp -> children[c];

            if (i == len - 1) {
                temp -> isLeaf = true;
            }

        }
    }
    

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* t = searchNode(word);
        return (t != nullptr && t->isLeaf);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchNode(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* t = new Trie();
    t -> insert("apple");
    cout << t -> search("apple") <<'\n';
    cout << t -> startsWith("app") << '\n';
    t -> insert("app");
    cout << t -> search("app") << '\n';
    return 0;
}
