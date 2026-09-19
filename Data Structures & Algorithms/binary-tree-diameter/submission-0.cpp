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
    int solve(TreeNode*root,int &curr_max){
        if(!root)return 0;
        if(root && root->left==NULL && root->right==NULL){
            return 1;
        }
        int left = solve(root->left,curr_max);
        int right = solve(root->right,curr_max);
        curr_max=max(curr_max,left+right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int curr_max=0;
        solve(root,curr_max);
        return curr_max;
    }
};
