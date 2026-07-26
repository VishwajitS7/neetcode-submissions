class Solution {
public:
    void solve(int ind, vector<int>& nums, int n, vector<vector<int>>& ans, vector<int>& curr){
        if(ind>=n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(ind+1, nums, n, ans, curr);
        curr.pop_back();
        while(ind+1 < n && nums[ind]==nums[ind+1]){
            ind++;
        }
        solve(ind+1, nums, n, ans, curr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        solve(0, nums, n, ans, curr);
        return ans;
    }
};
