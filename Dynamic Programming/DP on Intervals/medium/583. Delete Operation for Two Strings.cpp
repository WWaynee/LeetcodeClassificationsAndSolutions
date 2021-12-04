class Solution {
public:
    int minDistance(string word1, string word2) {
        //等同于求s1和s2的最长子串长度
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));
        //dp[i][j]表示s1的0~i-1和s2的0~j-1的最长子串长度
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n1+n2-2*dp[n1][n2];
    }
};