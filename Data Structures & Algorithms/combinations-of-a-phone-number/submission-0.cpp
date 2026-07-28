class Solution {
public:
    void solve(int ind, string digits, vector<string>& ans, string s, string combos[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int num = digits[ind]-'0';

        for(int i=0;i< combos[num].size();i++){
            solve(ind+1, digits, ans, s+combos[num][i], combos);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s="";
        solve(0, digits, ans, s, combos);
        return ans;
    }
};
