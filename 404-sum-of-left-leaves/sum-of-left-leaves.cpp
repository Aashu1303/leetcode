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
    int solve(TreeNode* &root , bool l){
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL && l) return root -> val;
        int left = solve(root -> left , true);
        int right = solve(root -> right , false);
        return left + right;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        return solve(root , 0);
    }
};