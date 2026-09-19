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
    unordered_map<int,int>seen;
    unordered_map<int,int>mp;
    unordered_map<int,TreeNode*>build;
    TreeNode* solve(vector<int>&a,vector<int>&b,int &idx,int l ,int r){        
        
        if(l > r || idx >= a.size()) return NULL;
        int val = a[idx++];

        if(seen[val]){
            return NULL;
        }
        if(l==r){return build[val];}
        
        TreeNode* curr = build[val];
        int new_range = mp[val];
        seen[val]++;

        curr->left = solve(a,b,idx,l,new_range-1);
        curr->right = solve(a,b,idx,new_range+1,r);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
            build[inorder[i]]=new TreeNode(inorder[i]);
        }
        int idx = 0;
        TreeNode * res = solve(preorder,inorder,idx,0,preorder.size()-1);
        return res;
        
    }
};
