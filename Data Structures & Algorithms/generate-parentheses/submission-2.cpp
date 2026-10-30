class Solution {
public:
    vector<string>res;
    bool valid(string str){
        stack<char>st;
        int idx = 0;
        while(idx<str.size()){
            if(str[idx]=='('){st.push(str[idx]);}
            else{
                if(!st.empty()){st.pop();}
                else{break;}
            }
            idx++;
        }
        return (st.empty() && idx>=str.size());
    }
    void solve(int l,string str){
        if(2*l==str.size()){
            if(valid(str)){res.push_back(str);}
            return;
        }
        solve(l,str+'(');
        solve(l,str+')');

    }
    vector<string> generateParenthesis(int n) {
        solve(n,"");
        return res;
    }
};
