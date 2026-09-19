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
    bool isSame(TreeNode*p,TreeNode*q){
        if(!p && !q)return true;
        if((!p && q)|| (p && !q) || (p && q && p->val!=q->val))
            return false;
        bool l = isSame(p->left,q->left);
        bool r = isSame(p->right,q->right);
        return l&&r;
    }
    bool isSubtree(TreeNode* p, TreeNode* t) {
        queue<TreeNode*>q;
        q.push(p);
        bool ans = false;
        while(!q.empty()){
            TreeNode*curr=q.front();q.pop();
            if(curr->val==t->val){
                TreeNode * temp=t;
                ans = ans|isSame(curr,temp);
            }
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        return ans;
    }
};
