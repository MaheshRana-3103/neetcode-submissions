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
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * curr=root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isLeaf=true;
    }
    
    bool search(string word) {
        TrieNode * curr=root;
        bool ans = true;
        for(int i=0;i<word.size();i++){
            if(word[i]!='.'){
                int idx = word[i]-'a';
                if(curr->children[idx]==nullptr){
                    return false;
                }
                curr=curr->children[idx];
            }
            else{
                bool res = false;
                for(int idx=0;idx<26;idx++){
                    if(curr->children[idx]!=nullptr){
                        word[i]=(char)(idx+'a');
                        bool res = search(word);
                        if(res){res=true;return res;}
                    }
                }
                if(res==false){
                    return res;
                }
            }
        }
        return curr->isLeaf;
    }
};
