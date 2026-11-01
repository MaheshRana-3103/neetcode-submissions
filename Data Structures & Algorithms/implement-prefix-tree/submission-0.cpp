class TrieNode{
    public:
        TrieNode *children[26];
        bool isLeaf;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
            isLeaf=false;
        }
};
class PrefixTree {
public:
    TrieNode *root;
    PrefixTree() {
       root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(curr->children[idx]==nullptr){
                TrieNode *new_node = new TrieNode();
                curr->children[idx]=new_node;
            }
            curr=curr->children[idx];
        }
        curr->isLeaf=true;
    }
    
    bool search(string word) {
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return (curr->isLeaf); 
    }
    
    bool startsWith(string prefix) {
        TrieNode*curr=root;
        for(int i=0;i<prefix.size();i++){
            int idx = prefix[i]-'a';
            if(curr->children[idx]==nullptr){
                return false;
            }
            curr=curr->children[idx];
        }
        return true; 
    }
};
