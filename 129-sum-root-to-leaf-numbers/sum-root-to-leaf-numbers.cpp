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
    void solve(TreeNode*&root , int prev , vector<int> &nums){
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL){
            nums.push_back(prev * 10 + root -> val);
            return;
        }
        solve(root->left,(prev*10)+root->val,nums);
        solve(root -> right , (prev*10)+root->val , nums);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        solve(root , 0 , temp);
        int sum = 0;
        for(auto i : temp) sum += i;
        return sum;        
    }
};