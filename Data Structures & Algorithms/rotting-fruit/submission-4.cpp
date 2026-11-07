class Solution {
public:
    vector<int>x_axis={1,-1,0,0};
    vector<int>y_axis={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){fresh++;}
            }
        }
        if(fresh==0){return 0;}

        int res = -1;
        while(!q.empty()){
            int sz=q.size();
            res++;
            while(sz--){
                auto it = q.front();q.pop();
                int x=it.first;
                int y=it.second;
                for(int u=0;u<4;u++){
                    int new_x=x+x_axis[u];
                    int new_y=y+y_axis[u];
                    if(new_x<0||new_y<0||new_x>=n||
                        new_y>=m||grid[new_x][new_y]!=1){
                        continue;
                    }
                    grid[new_x][new_y]=2;
                    fresh--;
                    q.push({new_x,new_y});
                }
            }
        }
        
        return (fresh==0)?res:-1;
    }
};
