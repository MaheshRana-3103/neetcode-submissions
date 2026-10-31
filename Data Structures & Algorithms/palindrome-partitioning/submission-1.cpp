class Solution {
public:
    vector<vector<string>>res;
    unordered_map<string,bool>mp;
    bool palindrome(int l,int r,string str){
        if(mp.find(str)!=mp.end()){return mp[str];}
        while(r>=l and str[l]==str[r]){
            l++,r--;
        }
        mp[str]=(r<l);
        return mp[str];
    }
    void solve(string s,vector<string>v){
        if(s.size()==0){
            res.push_back(v);
            return;
        }
        for(int i=0;i<s.size();i++){
            string curr_str = s.substr(0,i+1);
            if(palindrome(0,curr_str.size()-1,curr_str)){
                v.push_back(curr_str);
                solve(s.substr(i+1),v);
                v.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        solve(s,{});
        return res;        
    }
};
