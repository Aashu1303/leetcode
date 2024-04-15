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
    int ans = 0;
    void solve(TreeNode*&root , int prev){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            ans += prev * 10 + root -> val;
            return;
        }
        solve(root->left,(prev*10)+root->val);
        solve(root -> right , (prev*10)+root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        solve(root , 0);
        return ans;        
    }
};