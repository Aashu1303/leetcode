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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp -> left = root;
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int x = 1;
        while(!q.empty()){
            if(x == depth-1){
                int size = q.size()-1;
                for(int i = 0 ; i < size ; i++){
                    TreeNode* top = q.front();
                    TreeNode* left = top->left ? top -> left : nullptr;
                    TreeNode* temp = new TreeNode(val);
                    top -> left = temp;
                    temp -> left = left;
                    TreeNode* right = top->right ? top->right : nullptr;
                    temp = new TreeNode(val);
                    top -> right = temp;
                    temp -> right = right;
                    q.pop();
                }
                break;
            }
            if(q.front() == nullptr){
                q.pop();
                q.push(nullptr);
                x++;
                continue;
            }
            TreeNode* top = q.front();
            q.pop();
            if(top -> left != NULL){
                q.push(top -> left);
            }
            if(top -> right != NULL){
                q.push(top -> right);
            }
        }
        return root;
    }
};