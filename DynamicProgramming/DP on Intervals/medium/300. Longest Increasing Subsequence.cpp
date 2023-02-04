class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> dp(n+1,1);//dp[i]=j表示子序列0~i的最长递增长度
        int res = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};