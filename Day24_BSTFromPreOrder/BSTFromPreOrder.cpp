// Problem Link : https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/

// Construct Binary Search Tree from Preorder Traversal

/* Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct. */

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
class Solution {
    TreeNode* construct(vector<int>& preorder, int* preIndex, int key, int min, int max, int size) {
        if (*preIndex >= size) {
            return nullptr;
        }
        
        TreeNode* root = nullptr;
        
        if (key > min && key < max) {
            root = new TreeNode(key);
            * preIndex = *preIndex + 1;
            
            if (*preIndex < size) {
                root -> left = construct(preorder, preIndex, preorder[*preIndex], min, key, size);
            }
            if(*preIndex < size) {
                root -> right = construct(preorder, preIndex, preorder[*preIndex], key, max, size);
            }
        }
        
        return root;
    }
public:
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;
        int size = preorder.size();
        return construct(preorder, &preIndex, preorder[0], INT_MIN, INT_MAX, size);
    }
};