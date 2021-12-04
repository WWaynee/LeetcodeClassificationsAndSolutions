class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(),stones.end(),0);
        int half = sum >> 1;
        vector<bool> dp(half + 1,0);
        dp[0] = true;
        int i,j;
        for(i=0;i<stones.size();i++){//遍历物品
            for(j=half;j>=stones[i];j--){//遍历背包
                if(dp[j-stones[i]]) dp[j] = true;
            }
        }
        for(i=half;i>=0;i--) if(dp[i]) break;
        return sum-2*i;
    }
};