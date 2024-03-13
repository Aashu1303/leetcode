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
    int solve(TreeNode* root){
        if(root -> left == NULL && root -> right == NULL){
            return 1;
        }
        int left = INT_MAX , right = INT_MAX;
        if(root -> left != NULL){
            left = 1 + solve(root -> left);
        }
        if(root -> right != NULL){
            right = 1 + solve(root -> right);
        }

        return min(right , left);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = INT_MAX , right = INT_MAX;
        if(root -> left  != NULL){
            left = solve(root->left);
        }
        if(root -> right != NULL){
            right = solve(root -> right);
        }

        int ans = min(left , right);

        return ans == INT_MAX ? 1 : ans+1;
    }
};