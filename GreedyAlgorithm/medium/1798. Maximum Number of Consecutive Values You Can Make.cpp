class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        // 必定是从0开始
        // 贪心：遍历每一个硬币，然后与之前的连续区间里每个数字相加构造下一个连续区间
        // 区间用[0, n]表示
        sort(coins.begin(), coins.end());
        int n = 0, size = coins.size();
        for (int i = 0; i < size; i++) {
            if (coins[i] <= n + 1) {
                n = coins[i] + n;
            }
        }
        return n + 1;
    }
};