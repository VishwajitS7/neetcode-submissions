class Solution {
public:
    void solve(int ind, vector<int> &curr, vector<int> & nums, vector<vector<int>> &ans, int n){
        if(ind==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        solve(ind+1, curr, nums, ans, n);
        curr.pop_back();
        solve(ind+1, curr, nums, ans, n);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int ind=0;
        int n=nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        solve(ind, curr, nums, ans, n);
        return ans;
    }
};
