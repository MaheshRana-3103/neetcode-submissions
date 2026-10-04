class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&nums,vector<int>res){
        if(idx>=nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[idx]);
        solve(idx+1,nums,res);
        res.pop_back();
        solve(idx+1,nums,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        solve(0,nums,res);
        return ans;
    }
};
