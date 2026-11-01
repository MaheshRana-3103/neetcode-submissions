class Solution {
public:
    vector<vector<string>>res;
    bool isSafe(int x,int y , vector<string>&v,int n){
        for(int i=0;i<n;i++){
            if(v[x][i]=='Q')return false;
            if(v[i][y]=='Q')return false;
        }
        for(int i=x,j=y;i>=0&&j>=0;i--,j--){
            if(v[i][j]=='Q')return false;
        }
        for(int i=x,j=y;i>=0&&j<n;i--,j++){
            if(v[i][j]=='Q')return false;
        }

        return true;
    }
    void solve(vector<string>v,int queens,int x,int y,int n){
        if(isSafe(x,y,v,n)){
            v[x][y]='Q';
            if((queens-1)>0){
                for(int i=0;i<n;i++){
                    solve(v,queens-1,x+1,i,n);
                }
            }
            else{
                res.push_back(v);
                return;
            }
            v[x][y]='.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n,string(n,'.'));
        for(int i=0;i<n;i++){
            solve(v,n,0,i,n);
        }
        return res;

        
    }
};
