class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], res = nums[0];
        for(int i=1;i<n;i++){
            //什么情况下继承前面的和
            if(sum+nums[i]>=nums[i]) sum += nums[i];
            //什么时候独自美丽
            else sum = max(sum,nums[i]);
            res = max(sum,res);
        }
        return res;
    }
};