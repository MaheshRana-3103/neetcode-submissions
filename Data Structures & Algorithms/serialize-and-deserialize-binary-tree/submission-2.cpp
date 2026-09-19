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

class Codec {
public:

    // Encodes a tree to a single string.
    string solve(TreeNode*root){
        if(!root)return "N";
        string l = solve(root->left);
        string r = solve(root->right);

        string res = to_string(root->val)+','+l+','+r;
        return res;
    }
    string serialize(TreeNode* root) {
        string res = solve(root);
        cout<<res<<" ";
        return res;
    }
    vector<int>create(string s){
        vector<int> ans;

        stringstream ss(s);
        string temp;

        while (getline(ss, temp, ',')) {
            if (temp == "N") {
                ans.push_back(-1001);  // represent N as -1
            } else {
                ans.push_back(stoi(temp));
            }
        }
        return ans;
    }
    TreeNode*decode(vector<int>&data ,int &idx){
        if(data[idx]==-1001){
            idx++;
            return NULL;
        }
        TreeNode * curr = new TreeNode(data[idx]);
        idx++;
        curr->left = decode(data,idx);
        curr->right = decode(data,idx);
        return curr;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>a = create(data);
        int idx = 0;
        return decode(a,idx);
    }
};
