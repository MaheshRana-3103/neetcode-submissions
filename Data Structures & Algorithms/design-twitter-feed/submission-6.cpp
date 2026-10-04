class Twitter {
public:
    unordered_map<int ,vector<pair<int,int>>>mp;
    unordered_map<int,set<int>>f;
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
        set<int>followers = f[userId];
        for(auto f:followers){
            vector<pair<int,int>>f_user=mp[f];
            for(auto i:f_user){
                pq.push(i);
            }
        }  

        vector<pair<int,int>>current_user=mp[userId];
        for(auto i:current_user){
            pq.push(i);
        }
        while(res.size()<10 && !pq.empty()){
            auto it = pq.top();pq.pop();
            res.push_back(it.second);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       f[followerId].erase(followeeId);
    }
};
