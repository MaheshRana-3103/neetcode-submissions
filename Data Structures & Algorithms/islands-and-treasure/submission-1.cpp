class Solution {
public:
    vector<int>x_axis={1,-1,0,0};
    vector<int>y_axis={0,0,1,-1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();q.pop();
            int x=it.first;
            int y=it.second;
            for(int u=0;u<4;u++){
                int new_x=x+x_axis[u];
                int new_y=y+y_axis[u];
                if(new_x<0||new_y<0||new_x>=n||
                    new_y>=m||grid[new_x][new_y]==-1||
                        grid[new_x][new_y]!=INT_MAX){
                    continue;
                }
                grid[new_x][new_y]=1+grid[x][y];
                q.push({new_x,new_y});
            }
        }
    }
};
