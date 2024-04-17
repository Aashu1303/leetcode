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
    void solve(TreeNode*&root , string s , string &ans){
        if(root -> left == NULL && root -> right == NULL){
            int val = root -> val;
            s.push_back((val+'a'));
            reverse(s.begin(),s.end());
            ans = min(ans , s);
            return;
        }
        int val = root -> val;
        s.push_back((val+'a'));
        
        if(root -> left) solve(root->left , s , ans);        
        if(root -> right) solve(root->right , s , ans);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v; 
        string s , ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"; 
        solve(root , s , ans);
        //cout << char('a'+1) << endl;
        // for(auto i : v) s = min(s , i);
        return ans;
    }
};