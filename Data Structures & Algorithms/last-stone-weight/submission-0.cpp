class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>st;
        for(auto i:stones){
            st.push(i);
        }
        while(!st.empty()){
            int f = st.top();st.pop();
            if(st.empty()){
                return f;
            }
            int s = st.top();st.pop();
            int diff = abs(f-s);
            if(diff>0){st.push(diff);}
        }
        return 0;
    }
};
