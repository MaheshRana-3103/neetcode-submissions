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
    void solve(TreeNode*root,int curr_max,int &goodNodes)
    {
        if(!root){return;}
        if(root->val>=curr_max){
            goodNodes++;
            curr_max=root->val;
        }
        if(root->left)solve(root->left,curr_max,goodNodes);
        if(root->right)solve(root->right,curr_max,goodNodes);

    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int g = 0;
        solve(root,root->val,g);
        return g;
    }
};
