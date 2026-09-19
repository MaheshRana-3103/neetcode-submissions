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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        if(root && root->left==NULL && root->right==NULL){
            return root;
        }
        TreeNode * current = root;
        TreeNode* left= invertTree(current->left);
        TreeNode* right =  invertTree(current->right);
        TreeNode*temp = left;
        current->left = right;
        current->right = temp;
        return current;
    }
};
