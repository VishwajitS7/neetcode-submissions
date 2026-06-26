class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int pivot=0;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        pivot=l;
        int result= binary(nums,target,0,pivot-1);
        if(result!=-1){
            return result;
        }
        return binary(nums,target,pivot,nums.size()-1);
    }
    int binary(vector<int>& nums,int target, int left, int right){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};
