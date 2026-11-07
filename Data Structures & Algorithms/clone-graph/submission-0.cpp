/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        int root = node->val;
        mp[root]=new Node(root);
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto it  = q.front();q.pop();
            Node * curr = mp[it->val];
            for(auto i:it->neighbors){
               if(mp.find(i->val)==mp.end()){
                    Node *child = new Node(i->val);
                    mp[i->val]=child;
                    q.push(i);
               }
               curr->neighbors.push_back(mp[i->val]);
            }
        }
        return mp[root];
        
    }
};
