class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);//dp[i]=j表示能凑出i元总额有j种方案
        int n = coins.size();
        dp[0] = 1;
        for(int i=0;i<n;i++)
            for(int j=1;j<=amount;j++)
                if(j>=coins[i]) dp[j] += dp[j-coins[i]];
        return dp[amount];
    }
};