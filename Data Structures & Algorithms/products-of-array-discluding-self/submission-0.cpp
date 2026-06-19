class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prod=1;
        int zero_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero_cnt++;
            else prod*=nums[i];
        }
        if(zero_cnt>1) return vector<int>(nums.size(), 0);

        for(int i=0;i<nums.size();i++){
            if(zero_cnt>0) res[i]=(nums[i]==0)? prod: 0;
            else res[i]=prod/nums[i];
        }
        return res;
    }
};
