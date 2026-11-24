class Solution {
public:
    vector<int>adj[26];
    vector<bool>vis;
    bool compare(string x,string y){
        int len = min(x.size(),y.size());
        for(int i=0;i<len;i++){
            if(x[i]!=y[i]){
                adj[x[i]-'a'].push_back(y[i]-'a');
                return true;
            }
        }
        return (x.size()<=y.size());
    }
    string foreignDictionary(vector<string>& words) {
        vis.resize(26,false);
        for(int i=0;i<words.size();i++){
            for(auto j:words[i]){
                vis[j-'a']=1;
            }
        }
        for(int i=1;i<words.size();i++){
            if(!compare(words[i-1],words[i])){
                return "";
            }
        }
        vector<int>indeg(26,0);
        string res="";
        int total = 0;
        for(int i=0;i<26;i++){
            if(vis[i]){
                for(auto j:adj[i]){
                    indeg[j]++;
                }
                total++;
            }
        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(indeg[i]==0 && vis[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();q.pop();
            res+=(char)(curr+'a');
            for(auto i:adj[curr]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }

            }
        }
        return (res.size()==total)?res:"";
    }
};
