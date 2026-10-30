class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        set<vector<int>>mp;
        int n = nums.size();
        int last_idx = (1<<n);
        for(int i=0;i<last_idx;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                int curr_bit = (1<<j);
                if(curr_bit&i){
                    v.push_back(nums[j]);
                }
            }
            if(mp.find(v)!=mp.end())continue;
            mp.insert(v);
            res.push_back(v);
        }
        return res;
    }
};
