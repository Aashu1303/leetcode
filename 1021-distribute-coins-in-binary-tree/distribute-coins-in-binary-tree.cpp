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
    int solve(TreeNode* child , TreeNode *parent){
        if(child == NULL) return 0;
        int left = solve(child -> left , child) , right = solve(child -> right , child);
        int x = (child -> val) - 1;
        if(parent != NULL) parent -> val += x;
        
        return left +  right + abs(x);
    }
public:
    int distributeCoins(TreeNode* root) {
        return solve(root , root);
    }
};