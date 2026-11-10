class Solution {
public:
    vector<vector<bool>>vis;
    vector<int>x_axis={0,0,1,-1};
    vector<int>y_axis={1,-1,0,0};
    vector<vector<int>>res;
    void solve(vector<vector<char>>&b,queue<pair<int,int>>&q){
       while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            vis[x][y]=true;
            res[x][y]++;

            for(int u=0;u<4;u++){
                int new_x = x+x_axis[u];
                int new_y = y+y_axis[u];
                if(new_x<0||new_y<0||new_x>=b.size()||new_y>=b[0].size()
                    ||vis[new_x][new_y]||b[new_x][new_y]=='X'){
                        continue;
                    }
                q.push({new_x,new_y});
            }
       }

    }
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vis.resize(n,vector<bool>(m,false));
        res.resize(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){if(b[0][i]=='O')q.push({0,i});}
        for(int i=1;i<n;i++){if(b[i][0]=='O')q.push({i,0});}
        for(int i=0;i<n;i++){if(b[i][m-1]=='O')q.push({i,m-1});}
        for(int i=1;i<m;i++){if(b[n-1][i]=='O')q.push({(n-1),i});}
        solve(b,q);
        
        for(int i=1;i<(n-1);i++){
            for(int j=1;j<(m-1);j++){
                if(res[i][j]==0){
                    b[i][j]='X';
                }
            }
        }
        return;
    }
};
