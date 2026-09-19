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
    bool solve(TreeNode*root,int curr_min,int curr_max){
        if(!root)return true;
        bool curr = root->val>curr_min && root->val<curr_max;
        bool l = root->left?
                solve(root->left,curr_min,root->val):true;
        bool r = root->right?
                solve(root->right,root->val,curr_max):true;
        return l&&r&&curr;   
    }
    bool isValidBST(TreeNode* root) {
       return solve(root,INT_MIN,INT_MAX);
    }
};
