class Solution {
public:
    unordered_map<char,string>mp;
    vector<string>res;
    void solve(string digits,string v){
        if(digits.empty()){
            res.push_back(v);
            return;
        }
        string curr_str = mp[digits[0]];
        for(auto i:curr_str){
            solve(digits.substr(1),v+i);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        
        mp['2']="abc",mp['3']="def",mp['4']="ghi",mp['5']="jkl",
        mp['6']="mno",mp['7']="pqrs",mp['8']="tuv",mp['9']="wxyz";
        solve(digits,"");

        return res;

    }
};
