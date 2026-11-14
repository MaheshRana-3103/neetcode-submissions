class Solution {
public:
    unordered_set<string>st;
    unordered_map<string,int>vis;
    void create(string word,map<string,vector<string>>&mp){
        string str = word;
        for(int j=0;j<word.size();j++){
            for(char ch='a';ch<='z';ch++){
                char t = str[j];
                str[j]=ch;
                if(vis.find(str)!=vis.end() 
                    && str!=word){
                        mp[word].push_back(str);
                }
                str[j]=t;
            }
        }

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
       map<string,vector<string>>mp;
       int n=wl.size();
       for(auto i:wl){vis[i]++;}
       for(auto i:wl){create(i,mp);}
       create(beginWord,mp);
       int res=0;
       queue<string>q;
       q.push(beginWord);
       st.insert(beginWord);
       while(!q.empty()){
            int sz=q.size();
            res++;
            while(sz--){
                string curr=q.front();q.pop(); 
                for(auto i:mp[curr]){
                    if(i==endWord)return res+1;
                    if(st.find(i)!=st.end())continue;
                    q.push(i);
                    st.insert(i);
                } 
            }
       }
       return 0;

    }
};
