class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int t = i[2];
            adj[u].push_back({v,t});
        }
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, greater<>> pq;

        vector<int>dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto [di,u] = pq.top();pq.pop();

            if(di>dist[u])continue;

            for(auto j:adj[u]){
                auto [v,d]=j;
                if(dist[u]+d<dist[v]){
                    dist[v]=dist[u]+d;
                    pq.push({dist[v],v});
                }
            }
        }
        int mx = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            mx = max(mx,dist[i]);
        }
        return mx;
        
    }
};
