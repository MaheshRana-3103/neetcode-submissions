class Solution {
public:
    map<string,priority_queue<string,
    vector<string>,greater<>>>mp;
    vector<string>path;
    void dfs(string u){
       auto &pq  = mp[u];
       while(!pq.empty()){
          auto curr = pq.top();pq.pop();
          dfs(curr);
       }
       path.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets){
            string u = i[0];
            string v = i[1];
            mp[u].push(v);
        }
        dfs("JFK");
        reverse(path.begin(),path.end());
        return path;

    }
};
