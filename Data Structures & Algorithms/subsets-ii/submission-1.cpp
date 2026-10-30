class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>&nums,int idx,vector<int>v){
        if(idx==nums.size()){
            res.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        solve(nums,idx+1,v);
        v.pop_back();
        while((idx+1)<nums.size() && nums[idx]==nums[idx+1])        {idx++;}
        solve(nums,idx+1,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // set<vector<int>>mp;
        // int n = nums.size();
        // int last_idx = (1<<n);
        // for(int i=0;i<last_idx;i++){
        //     vector<int>v;
        //     for(int j=0;j<n;j++){
        //         int curr_bit = (1<<j);
        //         if(curr_bit&i){
        //             v.push_back(nums[j]);
        //         }
        //     }
        //     if(mp.find(v)!=mp.end())continue;
        //     mp.insert(v);
        //     res.push_back(v);
        // }
        solve(nums,0,{});
        return res;
    }
};
