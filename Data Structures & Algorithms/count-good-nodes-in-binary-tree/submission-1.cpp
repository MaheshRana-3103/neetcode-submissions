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
    int solve(TreeNode*root,int curr_max)
    {
        if(!root){return 0;}
        int res = 0;
        if(root->val>=curr_max){
            curr_max=root->val;
            res=1;
        }
        if(root->left)res+=solve(root->left,curr_max);
        if(root->right)res+=solve(root->right,curr_max);
        return res;
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        return solve(root,root->val);
        
    }
};
