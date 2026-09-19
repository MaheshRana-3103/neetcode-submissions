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
    int height(TreeNode *root,int& maxDiff){
        if(!root) 
            return 0;
        if(root && root->left==NULL and root->right==NULL)
            return 1;
        int left = height(root->left,maxDiff);
        int right = height(root->right,maxDiff);
        maxDiff = max(maxDiff,abs(right-left));

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int maxDiff=0;
        int answer = height(root,maxDiff);
        return maxDiff<=1;
    }
};
