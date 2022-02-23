class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(k == 0 || size == 0) return 0;
        //0无操作 1第1次买 2第1次卖 ……
        vector<vector<int> > dp(size, vector<int>(2 * k + 1, 0));
        for(int j = 1;j <= 2*k;j += 2){
            dp[0][j] = -prices[0];
        }
        for(int i = 1;i < size;i++){
            dp[i][0] = dp[i - 1][0];
            for(int j = 1;j <= 2*k;j+=2)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            for(int j = 2;j <= 2*k;j+=2)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
        }
        return dp[size - 1][2*k];
    }
};