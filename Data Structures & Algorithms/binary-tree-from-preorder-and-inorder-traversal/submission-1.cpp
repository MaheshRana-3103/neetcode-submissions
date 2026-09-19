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
    unordered_map<int,int>mp;
    TreeNode* solve(vector<int>&a,int &idx,int l ,int r){        
        
        if(l > r || idx >= a.size()) return NULL;
        int val = a[idx++];
        
        TreeNode* curr = new TreeNode(val);
        int new_range = mp[val];

        curr->left = solve(a,idx,l,new_range-1);
        curr->right = solve(a,idx,new_range+1,r);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx = 0;
        TreeNode * res = solve(preorder,idx,0,preorder.size()-1);
        return res;
        
    }
};
