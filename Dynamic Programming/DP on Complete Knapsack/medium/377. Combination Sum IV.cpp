typedef unsigned long long ull;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ull> dp(target+1,0);//dp[i]=j表示凑出目标数i有j种组合
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        int n = nums.size();
        for(int j=1;j<=target;j++){
            for(int i=0;i<n;i++){
                if(j>=nums[i]) dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};