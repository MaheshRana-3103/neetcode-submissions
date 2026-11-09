class Solution {
public:
    vector<vector<bool>>vis;
    vector<vector<int>>res;
    vector<int>x_axis={1,-1,0,0};
    vector<int>y_axis={0,0,-1,1};
    void solve(vector<vector<int>>h,queue<pair<int,int>>&q){
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            res[x][y]++;
            for(int u=0;u<4;u++){
                int new_x = x+x_axis[u];
                int new_y=y+y_axis[u];
                if(new_x<0||new_y<0||
                new_x>=h.size()||new_y>=h[0].size()||
                vis[new_x][new_y]|| h[new_x][new_y]<h[x][y]){
                    continue;
                }              
                q.push({new_x,new_y});vis[new_x][new_y]=true;

            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>>ans;
        vis.resize(n,vector<bool>(m,false));
        
        res.resize(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){q.push({0,i});vis[0][i]=true;}
        for(int i=1;i<n;i++){q.push({i,0});vis[i][0]=true;}
        solve(h,q);

        vis.assign(n,vector<bool>(m,false));
        
        while(!q.empty()){q.pop();}
        for(int i=0;i<m;i++){q.push({(n-1),i});vis[n-1][i]=true;}
        for(int i=0;i<(n-1);i++){q.push({i,(m-1)});vis[i][m-1]=true;}
        solve(h,q);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]==2){
                    ans.push_back({i,j});
                }
            }
            
        }
        return ans;

        
    }
};
