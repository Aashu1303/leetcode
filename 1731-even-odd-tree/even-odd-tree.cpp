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
public:
    bool isEvenOddTree(TreeNode* root) {
        // do level wise traversing and find whether the given level satisfy the given condition or not
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1; // 1 -> even && 0 -> odd
        while(!q.empty()){
            int n = q.size();
            int prev = (flag == 1)? INT_MIN : INT_MAX;
            for(int i = 0 ; i < n ; i++){
                TreeNode* top = q.front();
                q.pop();

                if(flag){
                    // strictly increasing and should be an odd number
                    if(top -> val <= prev || top -> val % 2 == 0){
                        return false;
                    } 
                }else{
                    // strictly decreasing and should be an even number
                    if(top -> val >= prev || top -> val % 2 != 0){
                        return false;
                    }
                }

                if(top -> left != NULL){
                    q.push(top -> left);
                }
                if(top -> right != NULL){
                    q.push(top -> right);
                }
                prev = top -> val;
            }
            flag = !flag;
        }
        return true;
    }
};