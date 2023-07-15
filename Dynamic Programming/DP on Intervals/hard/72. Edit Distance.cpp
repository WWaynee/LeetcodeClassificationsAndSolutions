class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        //dp[i][j]=k表示将s1的0~i-1子串转换成s2的0~j-1子串的最少操作数
        vector<vector<int> > dp(n1+1,vector<int>(n2+1,0));
        //初始化
        for(int i=0;i<=n1;i++) dp[i][0] = i;
        for(int i=0;i<=n2;i++) dp[0][i] = i;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                //插入是删除的反操作，替换是替换的反操作
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
                }
            }
        }
        return dp[n1][n2];
    }
};