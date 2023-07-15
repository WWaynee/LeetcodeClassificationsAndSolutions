class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp过程
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        //dp[i][j]表示i个0和j个1能表示的最大长度，转移方程:
        for(int i=0;i<strs.size();i++){//遍历物品
            int zeros = 0, ones = 0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') zeros++;
                else ones++;
            }
            for(int j=m;j>=zeros;j--){//遍历背包
                for(int k=n;k>=ones;k--){
                    dp[j][k] = max(dp[j][k],dp[j-zeros][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};