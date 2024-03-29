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
    int solve(TreeNode* root , int& ans){
        if(root == NULL){
            return 0;
        }
        int left = solve(root -> left , ans);
        int right = solve(root -> right,ans);

        ans = max(ans , left+right);
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int x = solve(root , ans);
        //cout << x << endl;
        return ans;
    }
};