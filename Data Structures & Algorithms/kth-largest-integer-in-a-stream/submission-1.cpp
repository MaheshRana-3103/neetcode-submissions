class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>t;
    int cap; 
    KthLargest(int k, vector<int>& nums) {
        cap=k;
        for(int i=0;i<nums.size();i++){
            t.push(nums[i]);
        }
    }
    
    int add(int val) {
        t.push(val);
        while(t.size()>cap){
            t.pop();
        }
       return t.top();
    }
};
