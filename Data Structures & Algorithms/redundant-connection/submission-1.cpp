class DSU{
    public:
        vector<int>parent,sz;
        DSU(int n){
            parent.resize(n,0);
            sz.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
                sz[i]=1;
            }
        }
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x] = find(parent[x]);
        } 
        bool merge(int x,int y){
            x=find(x);
            y=find(y);
            if(x==y)return false;
            if(sz[x]<sz[y])swap(x,y);
            parent[y]=x;
            sz[x]+=sz[y];
            return true;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>res={-1,-1};
        int n=edges.size();
        DSU *d = new DSU(n+1);
        for(auto e:edges){
            bool ans = d->merge(e[0],e[1]);
            if(!ans){
                res[0]=e[0];
                res[1]=e[1];
                break;
            }
        }
        
        return res;
    }
};
