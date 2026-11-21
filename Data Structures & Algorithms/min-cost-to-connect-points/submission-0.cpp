class Solution {
public:
    map<pair<int,int>,vector<vector<int>>>mp;
    set<pair<int,int>>s;
    int solve (int x ,int y){
        priority_queue<vector<int>,
        vector<vector<int>>,greater<>>pq;
        pq.push({0,x,y});
        int res = 0;
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            if(s.find({it[1],it[2]})!=s.end()){
                continue;
            }
            s.insert({it[1],it[2]});
            res+=it[0];
            pair<int,int>curr = {it[1],it[2]};
            for(auto i:mp[curr]){
                if(s.find({i[1],i[2]})!=s.end())continue;
                pq.push(i);
            }
        }
        return res;

    }
    int minCostConnectPoints(vector<vector<int>>& p) {

        for(int i=0;i<p.size();i++){
            int x = p[i][0];
            int y = p[i][1];
            for(int j=0;j<p.size();j++){
                int c_x = p[j][0];
                int c_y = p[j][1]; 
                int d = abs(x-c_x)+abs(y-c_y);
                mp[{x,y}].push_back({d,c_x,c_y});
            }
        }
       
        return solve(p[0][0],p[0][1]);

    }
};
