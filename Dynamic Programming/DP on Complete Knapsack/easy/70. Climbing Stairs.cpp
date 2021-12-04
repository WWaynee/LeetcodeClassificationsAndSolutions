class Solution {
public:
    int climbStairs(int n) {
        //dp[i]=j表示爬i阶楼梯有j种方法
        vector<int> dp(n+1,0);
        if(n>=1) dp[1] = 1; 
        if(n>=2) dp[2] = 2;
        //dp过程：dp[m] = dp[m-1] + dp[m-2]
        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};