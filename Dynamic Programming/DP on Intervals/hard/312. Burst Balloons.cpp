class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int> > dp(n+2,vector<int>(n+2,0));
        for(int k=1;k<=n;k++){//戳破气球的个数从1~n
            for(int i=1;i<=n-k+1;i++){//左侧边界
                int j = i+k-1;//右侧边界
                for(int m=i;m<=j;m++){//取最大值
                    dp[i][j] = max(dp[i][j],dp[i][m-1]+dp[m+1][j]+nums[m]*nums[j+1]*nums[i-1]);
                }
            }
        }
        return dp[1][n];
    }
};