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
    int solve(TreeNode*root,int &res){
        if(!root)return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int current_node=root->val;
        res = max({res,current_node,current_node+l+r,current_node + max(l,r)});
        return max(current_node,current_node + max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;

    }
};
