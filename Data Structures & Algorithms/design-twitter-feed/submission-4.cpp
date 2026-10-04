class Twitter {
public:
    unordered_map<int ,vector<pair<int,int>>>mp;
    unordered_map<int,vector<int>>f;
    int counter = 0;
    Twitter() {       
    }
    
    void postTweet(int userId, int tweetId) {
        counter++;
        mp[userId].push_back({counter,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        vector<int>followers = f[userId];
        for(int i=0;i<followers.size();i++){
            vector<pair<int,int>>f_user=mp[followers[i]];
            for(auto i:f_user){
                pq.push(i);
            }
        }  

        vector<pair<int,int>>current_user=mp[userId];
        for(auto i:current_user){
            pq.push(i);
        }
        int cntr = 10;
        while(cntr>0 && !pq.empty()){
            auto it = pq.top();pq.pop();
            res.push_back(it.second);
            cntr--;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(f[followerId].size()>0){
            for(auto i:f[followerId]){
                if(i==followeeId)
                return;
            }
        }
        f[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto &v = f[followerId];
        auto it = find(v.begin(), v.end(), followeeId);
        if (it != v.end()) {
            v.erase(it);
        }
    }
};
