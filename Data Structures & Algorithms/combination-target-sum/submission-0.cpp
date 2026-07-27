class Solution {
public:
    void solve(int ind, vector<int>& candidates, int n, int sum, vector<vector<int>>& ans, vector<int>& curr){
        if(sum==0){
            ans.push_back(curr);
            return;
        }
        if(sum<0 || ind == n) return;
        sum-=candidates[ind];
        curr.push_back(candidates[ind]);
        solve(ind, candidates, n, sum, ans, curr);

        sum+=candidates[ind];
        curr.pop_back();
        solve(ind+1, candidates, n, sum, ans, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        solve(0, nums, n, target, ans, curr);
        return ans;
    }
};
