class Solution {
public:
    vector<vector<int>>res;
    void solve(int l ,int r ,vector<int>&nums,vector<int>&ds,vector<bool>&freq){
        if(ds.size()==nums.size()){
            res.push_back(ds);
            return;
        }

        for(int i=l;i<r;i++){
            if(!freq[i]){
                freq[i]=true;
                ds.push_back(nums[i]);
                solve(l,r,nums,ds,freq);
                ds.pop_back();
                freq[i]=false;
            }
        }
       

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>freq(nums.size(),false);
        vector<int>ds;
        solve(0,nums.size(),nums,ds,freq);
        return res;
    }
};
