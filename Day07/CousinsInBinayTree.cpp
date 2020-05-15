// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

/* Cousins in Binary Tree
 */

/* In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

1. The number of nodes in the tree will be between 2 and 100.
2. Each node has a unique integer value from 1 to 100. */


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Triplet {
public :
    TreeNode* node;
    TreeNode* parent;
    int h;
    Triplet(TreeNode* node, TreeNode* parent, int h) : node(node), parent(parent), h(h) {}
};
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<Triplet*> q;
        Triplet* t1 = nullptr;
        Triplet* t2 = nullptr;
        Triplet* r = new Triplet(root, nullptr, 0);
        int count = 0;
        q.push(r);
        while(!q.empty() && count < 2) {
            Triplet* curr = q.front();
            q.pop();
            int currVal = (curr -> node) -> val;
            TreeNode* left = (curr -> node) -> left;
            TreeNode* right = (curr -> node) -> right;
            int h = curr ->  h; 
            if(currVal == x || currVal == y) {
                count ++;
                if(currVal == x) {
                    t1 = curr;
                }
                else {
                    t2 = curr;
                }
            }
            
            if(left != nullptr) {
                q.push(new Triplet(left, curr -> node, h + 1));
            }
            if(right != nullptr) {
                q.push(new Triplet(right, curr -> node, h + 1));
            }
        }
        
        if(count < 2 || x == y) return false;
        
        if(t1 -> parent != t2 -> parent && t1 -> h == t2 -> h) return true;
        return false;
        
    }
};