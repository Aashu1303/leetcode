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
    int solve(TreeNode* &root){
        if(root == NULL) return 0;
        int left = solve(root -> left);
        int right = solve(root -> right);
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1){
            return -1;
        } 
        return 1 + max(left , right);
    }
public:
    bool isBalanced(TreeNode* root) {
        // if the height of the left subtree and the rightsubtree at any node of the given binary tree is strictly less than 2 then the binary is balanced
        return (solve(root)==-1)? 0 : 1;
    }
};