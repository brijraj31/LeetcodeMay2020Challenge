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
package Day14;
import java.util.HashMap;
import java.util.Map;

class Trie {
    private static class TrieNode {
        boolean isLeaf;
        private final Map<Character, TrieNode> children;

        private TrieNode() {
            children = new HashMap<Character, TrieNode>();
            isLeaf = false;
        }
        private TrieNode(final char c) {
            children = new HashMap<Character, TrieNode>();
            children.put(c, new TrieNode());
            isLeaf = false;

        }
    }

    private final TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    public void insert(final String word) {
        TrieNode temp = root;

        for (int i = 0; i < word.length(); ++i) {
            final char c = word.charAt(i);
                    
            if (!temp.children.containsKey(c)) {
                temp.children.put(c, new TrieNode());
            }

            temp = temp.children.get(c);

            if (i == word.length() - 1) {
                temp.isLeaf = true;
            }
        }
    }

    /** Returns if the word is in the trie. */

    public boolean search(final String word) {
        final TrieNode t = searchNode(word);

        return (t != null && t.isLeaf);

    }

    private TrieNode searchNode(final String word) {
        TrieNode temp = root;

        for (int i = 0; i < word.length(); ++i) {
            final char c = word.charAt(i);

            if (temp.children.containsKey(c))
                temp = temp.children.get(c);
            else
                return null;
        }

        return temp;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(final String prefix) {
        return searchNode(prefix) != null;
    }

    public static void main(final String[] args) {
        final Trie t = new Trie();

        t.insert("apple");
        System.out.println(t.search("apple"));
        System.out.println(t.search("app"));
        System.out.println(t.startsWith("app"));
        t.insert("app");
        System.out.println(t.search("app"));
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */