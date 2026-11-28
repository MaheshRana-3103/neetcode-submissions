class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>pq;
        vector<int>dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            if(k==-1){break;}
            int sz = pq.size();
            while(sz--){
                auto [d,u] = pq.front();pq.pop();
                for(auto curr:adj[u]){
                    int v = curr.first;
                    int wt = curr.second;
                    if(dist[v]>d+wt){
                        dist[v]=d+wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            k--;
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];

    }
};
