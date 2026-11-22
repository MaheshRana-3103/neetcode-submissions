class Solution {
public:
    vector<int>x_axis={0,0,1,-1};
    vector<int>y_axis={1,-1,0,0};

    bool solve(vector<vector<int>>&g,int tar){
        int n = g.size();
        int m = g[0].size();
        queue<pair<int,int>>q;
        unordered_map<int,int>mp;
        if(tar>=g[0][0]){
            q.push({0,0});
            mp[g[0][0]]++;
        }

        while(!q.empty()){
            auto [i,j]=q.front();q.pop();
            if(i==(n-1) && j==(m-1)){
                return true;
            }
            for(int u=0;u<4;u++){
                int new_x = i+x_axis[u];
                int new_y = j+y_axis[u];
                if(new_x<0||new_y<0||new_x>=n||new_y>=m 
                || g[new_x][new_y]>tar ){
                    continue;
                }
                if(mp.find(g[new_x][new_y])!=mp.end()){
                    continue;
                } 
                q.push({new_x,new_y});
                mp[g[new_x][new_y]]++;
            }
            
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& g) {
        int mx = g[0][0];
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                mx = max(mx,g[i][j]);
            }
        }
        int l = 0,r=mx;
        int timer = 0;
        while(r>=l){
            int m=l+(r-l)/2;
            if(solve(g,m)){
                timer = m;r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return timer;
    }
};
