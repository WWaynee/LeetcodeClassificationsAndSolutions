class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<int> buy(size, 0);
        vector<int> sell(size, 0);
        buy[0] = -prices[0];
        for(int i = 1;i < size;i++){
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
        }
        return sell[size - 1];
    }
};