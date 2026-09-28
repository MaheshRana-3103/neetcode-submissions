class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter = 0;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        queue<pair<int,char>>q;
        for(auto i:tasks){
            mp[i]++;
        }
        for(auto i:mp){pq.push({i.second,i.first});}
        int num = 0;
        while(!pq.empty()||!q.empty()){
            counter++;

            if(!q.empty()){
                auto it = q.front();q.pop();
                if(it.second!='-'){
                    pq.push(it);
                }
            }

            if(!pq.empty()){
                auto it = pq.top();pq.pop();
                int cnt = it.first-1;
                if(cnt>0){
                    int temp = q.size()<=n?(n-q.size()):0;
                    while(temp--){q.push({0,'-'});}
                    q.push({cnt,it.second});
                }
            }

        }
        return counter;
    }
};
