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
            return parent[x]=find(parent[x]);
        }
        bool merge(int x,int y){
            x = find(x);
            y = find(y);
            if(x==y){return false;}
            int rx = sz[x];
            int ry = sz[y];
            if(rx<ry){swap(x,y);}
            parent[y]=x;
            sz[x]+=sz[y];
            return true;
        }
};
class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        DSU * d = new DSU(n);
        int e = 0;
        for(auto i:edges){
            bool res = d->merge(i[0],i[1]);
            if(res==false){return false;}
            e++;
        }
        return (e==(n-1));
       
    }
};
