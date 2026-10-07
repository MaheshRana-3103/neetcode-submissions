class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>&nums,int idx,int target,vector<int>ans){
        if(idx>=nums.size() && target>0){return;}

        if(target<=0){
            if(target==0)res.push_back(ans);
            return;
        }

        if(nums[idx]<=target){
            ans.push_back(nums[idx]);
            solve(nums,idx,target-nums[idx],ans);
            ans.pop_back();
            solve(nums,idx+1,target,ans);
        }
        else{
            solve(nums,idx+1,target,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ans;
        int i = 0;
        solve(nums,i,target,ans);
        return res;
        
    }
};
