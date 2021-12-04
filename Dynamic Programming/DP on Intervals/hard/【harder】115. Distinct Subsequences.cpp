class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<double> > dp(n1+1,vector<double>(n2+1,0));
        //dp[i][j]=k表示s的0~i-1有k种t的0~j-1子序列
        for(int i=0;i<=n1;i++) dp[i][0] = 1;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(j>i) continue;
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};