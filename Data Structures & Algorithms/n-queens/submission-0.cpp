class Solution {
public:
    vector<vector<bool>>vis;
    vector<vector<string>>res;
    bool isSafe(int x,int y , vector<string>&v,int n){
        for(int i=0;i<n;i++){
            if(v[x][i]=='Q')return false;
            if(v[i][y]=='Q')return false;
        }
        for(int i=x,j=y;i<n&&j<n;i++,j++){
            if(v[i][j]=='Q')return false;
        }
        for(int i=x,j=y;i<n&&j>=0;i++,j--){
            if(v[i][j]=='Q')return false;
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
        for(int i=0;i<n;i++){
            if(isSafe(x,y,v,n)){
                v[x][y]='Q';
                if((queens-1)>0){solve(v,queens-1,x+1,i,n);}
                else{
                    res.push_back(v);
                    return;
                }
                v[x][y]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vis.resize(n,vector<bool>(n,false));
        vector<string>v;
        string str="";
        for(int i=0;i<n;i++){str+='.';}
        for(int i=0;i<n;i++){v.push_back(str);}
        
        for(int i=0;i<n;i++){
            solve(v,n,0,i,n);
        }
        return res;

        
    }
};
