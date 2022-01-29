class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0;i < size;i++){
            sum += nums[i];
        }
        //特殊情况
        if(abs(target) > abs(sum)) return 0;
        if((sum + target) % 2 == 1) return 0;
        //val保持正号，sum-val保持负号
        int val = (target + sum)/2;
        //dp[i]=j代表数组凑出数字i的方法有j种
        vector<int> dp(val + 1, 0);
        dp[0] = 1;
        for(int i = 0;i < size;i++){//遍历物品
            for(int j = val;j >= 0;j--){
                if(j - nums[i] >= 0) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[val];
    }
};