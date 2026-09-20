class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>t;
    int cap; 
    KthLargest(int k, vector<int>& nums) {
        cap=k;
        for(int i=0;i<nums.size();i++){
            t.push(nums[i]);
            if(t.size()>cap){t.pop();}
        }
    }
    
    int add(int val) {
        t.push(val);
        if(t.size()>cap){t.pop();}
       return t.top();
    }
};
