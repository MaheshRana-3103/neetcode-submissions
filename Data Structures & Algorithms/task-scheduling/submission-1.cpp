class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter = 0;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        deque<pair<int,char>>dq;
        for(auto i:tasks){
            mp[i]++;
        }
        for(auto i:mp){pq.push({i.second,i.first});}
        int num = 0;
        while(!pq.empty()||!dq.empty()){
            counter++;

            if(!dq.empty()){
                auto it = dq.front();dq.pop_front();
                if(it.second!='-'){
                    pq.push(it);
                }
            }

            if(!pq.empty()){
                auto it = pq.top();pq.pop();
                int cnt = it.first-1;
                if(cnt>0){
                    int temp = dq.size()<=n?(n-dq.size()):0;
                    while(temp--){dq.push_back({0,'-'});}
                    dq.push_back({cnt,it.second});
                }
            }

        }
        return counter;
    }
};
