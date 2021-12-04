class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int size = nums.size();
        double **dp = new double*[size];
        //dp[i][j]表示截止到第i个元素分成k份的最大和
        double *sum = new double[size], ans = 0;//前缀和
        for(int i=0;i<size;i++) {
            dp[i] = new double[k+1];
            //计算前缀和
            sum[i] = nums[i] + ans;
            ans =  sum[i];
            for(int j=0;j<=k;j++) dp[i][j] = 0;
            //计算dp初始数据，当划分为1组时
            dp[i][1] = sum[i]/(i+1);
        }
        //dp过程,划分为k组的解来自划分为k-1组时的解
        for(int i=1;i<size;i++){//从第2个数字开始划分
            for(int j=min(i+1,k);j>1;j--){//分为j组
                for(int m=0;m<i;m++){//根据j-1组的情况计算
                    dp[i][j] = max(dp[m][j-1]+(sum[i]-sum[m])/(i-m),dp[i][j]);
                }
            }
        }
        return dp[size-1][k];
    }
};