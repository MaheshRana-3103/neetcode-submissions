class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        queue<int>q;
        vector<int>indeg(n,0);
        vector<vector<int>>g(n);
        for(auto i:p){
            int x = i[0];
            int y = i[1];
            g[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            for(auto j:g[i]){
                indeg[j]++;
            }
        }
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){q.push(i);}
        }
        vector<int>res;
        while(!q.empty()){
            int curr = q.front();q.pop();
            res.push_back(curr);
            for(auto i:g[curr]){
                if(--indeg[i]==0){
                    q.push(i);
                }
            }
        }
        return (res.size()==n);
    }
};
