class Solution {
public:
    vector<int>x_axis={-1,1,0,0};
    vector<int>y_axis={0,0,1,-1};
    vector<vector<bool>>vis;
    bool solve(vector<vector<char>>&b,string word,
        int x,int y,int idx){
            if(idx==word.size()){return true;}

            if(x<0||y<0||x>=b.size()||y>=b[0].size()){
                return false;
            }
            if(vis[x][y])return false;
            bool ans = false;
            if(b[x][y]==word[idx]){
                vis[x][y]=true;
                for(int i=0;i<x_axis.size();i++){
                    ans|=
                    solve(b,word,x+x_axis[i],y+y_axis[i],idx+1);
                }
                vis[x][y]=false;
            }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vis.resize(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
