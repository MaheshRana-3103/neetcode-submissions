class Solution {
public:
    vector<int>x_axis={0,0,1,-1};
    vector<int>y_axis={1,-1,0,0};

    int solve(vector<vector<int>>&g){
        int n = g.size();
        int m = g[0].size();
        priority_queue<vector<int>,
        vector<vector<int>>,greater<>>q;
        unordered_map<int,int>mp;
        q.push({g[0][0],0,0});
        while(!q.empty()){
            auto it=q.top();q.pop();
            int d = it[0];
            int i = it[1];
            int j = it[2];

            if(i==(n-1) && j==(m-1)){
                return d; 
            }
            if(mp[g[i][j]]){continue;}
            mp[g[i][j]]++;

            for(int u=0;u<4;u++){
                int new_x = i+x_axis[u];
                int new_y = j+y_axis[u];
                if(new_x<0||new_y<0||new_x>=n||new_y>=m){
                    continue;
                }
                if(mp.find(g[new_x][new_y])!=mp.end()){
                    continue;
                } 
                int mx = max(d,g[new_x][new_y]);
                q.push({mx,new_x,new_y});
            }
            
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& g) {
       return solve(g);
    }
};
