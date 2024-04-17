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
    void solve(TreeNode*&root , string s , vector<string>&v){
        if(root -> left == NULL && root -> right == NULL){
            int val = root -> val;
            s.push_back((val+'a'));
            reverse(s.begin(),s.end());
            v.push_back(s);
            return;
        }
        int val = root -> val;
        s.push_back((val+'a'));
        
        if(root -> left) solve(root->left , s , v);        
        if(root -> right) solve(root->right , s , v);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v; string s;
        solve(root , s , v);
        s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        //cout << char('a'+1) << endl;
        for(auto i : v) s = min(s , i);
        return s;
    }
};