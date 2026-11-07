class Solution {
public:
    vector<int>x_axis={1,-1,0,0};
    vector<int>y_axis={0,0,1,-1};
    void islands(vector<vector<char>>&b,int i ,int j){
        if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]=='0'){
            return;
        }
        b[i][j]='0';
        for(int u = 0;u<4;u++){
            islands(b,x_axis[u]+i,j+y_axis[u]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res++;
                    islands(grid,i,j);
                }
            }
        }
        return res;
    }
};
