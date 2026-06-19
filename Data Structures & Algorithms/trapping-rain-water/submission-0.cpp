class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        int n=height.size();
        int res=0;
        int left=0,right=n-1;
        int leftMax=height[left],rightMax=height[right];
        while(left<right){
            if(leftMax<rightMax){
                left++;
                leftMax=max(leftMax,height[left]);
                res+= leftMax-height[left];
            }
            else{
                right--;
                rightMax=max(rightMax,height[right]);
                res+=rightMax-height[right];
            }
        }
        return res;
    }
};
