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
class Solution {
public:
    vector<int>x_axis={1,-1,0,0};
    vector<int>y_axis={0,0,1,-1};
    vector<string>res;
    void insert(string word,TrieNode*root){
        TrieNode*curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }        
        curr->isLeaf=true;
    }
    void solve(vector<vector<char>>&b,
    int i,int j,char cand,TrieNode*curr,string str){
        if(i<0||j<0||i>=b.size()||j>=b[0].size()||
        b[i][j]!=cand||b[i][j]=='#'){
            return;
        }
        if(curr->isLeaf){
            res.push_back(str);
            curr->isLeaf=false;
        }
        b[i][j]='#';

        for(int idx=0;idx<26;idx++){
            if(curr->children[idx]!=nullptr){
                for(int u=0;u<4;u++){
                    int x=i+x_axis[u];
                    int y=j+y_axis[u];
                    char cand = (idx+'a');
                    solve(b,x,y,cand,curr->children[idx],str+cand);
                }
            }
        }
        b[i][j]=cand;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++){
            insert(words[i],root);
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int idx = board[i][j]-'a';
                TrieNode * curr = root;
                if(root->children[idx]!=nullptr){
                    char cand = board[i][j];
                    string str = "";
                    str+=cand;
                    solve(board,i,j,
                    board[i][j],curr->children[idx],str);
                }
            }
        }
        return res;

        
        
    }
};
