class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 1. 元素和相等代表数组和一定是偶数，而且分成两份是定值
        // 2. 0-1背包问题，每个数字取1次
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum >>= 1;//背包的最大值，问题等价于能不能从数组中找几个数字的和为sum
        // dp[i]代表数组能不能找出若干数字凑出综合i
        int n = nums.size();
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=0;i<n;i++){//遍历物品
            for(int j=sum;j>=nums[i];j--){//倒序遍历背包
                dp[j] = (dp[j-nums[i]] || dp[j]);
            }
        }
        return dp[sum];
    }
};