class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        //dp状态 0买入 1卖出 2冷冻
        vector<vector<int> > dp(size, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for(int i = 1;i < size;i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[size - 1][0], max(dp[size - 1][1], dp[size - 1][2]));
    }
};