class Solution {
public:
    void solve(int ind, vector<int>& candidates, int n, int sum, vector<vector<int>>& ans, vector<int>& curr){
        if(sum==0){
            ans.push_back(curr);
            return;
        }
        if(sum<0 || ind == n) return;
        curr.push_back(candidates[ind]);
        sum-=candidates[ind];
        solve(ind+1, candidates, n, sum, ans, curr);

        curr.pop_back();
        sum+=candidates[ind];
        for(int i= ind+1; i< n; i++){
            if(candidates[i]!= candidates[ind]){
                solve(i, candidates, n, sum, ans, curr);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, n, target, ans, curr);
        return ans;
    }
};
