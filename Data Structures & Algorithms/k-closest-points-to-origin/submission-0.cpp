class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,
        vector<pair<double, vector<int>>>,
        greater<pair<double, vector<int>>>>pq;

        for(auto i:points){
            int x = i[0];
            int y = i[1];
            double res = sqrt(pow(x,2)+pow(y,2));
            pq.push({res,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            auto i = pq.top();pq.pop();
            ans.push_back(i.second);
        }
        return ans;
    }
};
