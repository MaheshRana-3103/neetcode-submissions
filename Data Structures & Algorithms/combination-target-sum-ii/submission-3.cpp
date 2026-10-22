class Solution {
public:
    int next_idx(vector<int>&nums,int tar,int idx){
        int l = idx;
        int r = nums.size()-1;
        int ans = -1;
        while(r>=l){
            int mid = l+(r-l)/2;
            if(nums[mid]<=tar){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
    void solve(vector<int>&nums,int idx,int target,vector<int>&ans,vector<vector<int>>&res){
        if(idx>=nums.size() && target>0){return;}

        if(target<=0){
            if(target==0){res.push_back(ans);}
            return;
        }

        if(nums[idx]<=target){
            ans.push_back(nums[idx]);
            solve(nums,idx+1,target-nums[idx],ans,res);
            ans.pop_back();
            int index = next_idx(nums,nums[idx],idx);
            if(index==-1)return;
            solve(nums,index,target,ans,res);
        }
        else{
            solve(nums,idx+1,target,ans,res);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int idx=0;
        vector<vector<int>>res;
        vector<int>ans;
        solve(candidates,idx,target,ans,res);
        return res;
        
    }
};
