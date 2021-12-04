class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();
        vector<int> dp(amount+1,99999);//dp[i]代表能凑出总额为j时的最少硬币数
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i]){
                    if(j%coins[i]==0) dp[j] = min(dp[j],j/coins[i]);
                    dp[j] = min(dp[j],1+dp[j-coins[i]]);
                }
            }
        }
        if(dp[amount]==99999) return -1;
        return dp[amount];
    }
};