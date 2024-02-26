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
    void levelorderTraversal(TreeNode* root , vector<int> &v){
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                v.push_back(temp -> val);
            }else{
                v.push_back(INT_MIN);
                continue;
            }
            
            q.push(temp -> left);            
            q.push(temp -> right);
            
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1 , v2;
        levelorderTraversal(p,v1);
        levelorderTraversal(q,v2);
        if(v1.size() != v2.size()) return false;

        for(int i = 0 ; i < v1.size() ; i++){
            if(v1[i] != v2[i]) return false;
        }

        return true;
    }
};