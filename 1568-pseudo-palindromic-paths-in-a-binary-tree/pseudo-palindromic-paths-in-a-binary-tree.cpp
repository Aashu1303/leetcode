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
    void traversal(TreeNode * root , vector<int> &v){
        if(root == NULL){
            return;
        }
        v[root -> val]++;
        if(root -> left == NULL && root -> right == NULL){
            int count =0;
            for(auto i : v){
                if(i % 2 != 0) count++;
            }
            ans += (count <= 1) ? 1 : 0;
        }

        traversal(root -> left , v);
        traversal(root -> right , v);
        v[root -> val]--;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10,0);
        traversal(root,temp);
        return ans;        
    }
};