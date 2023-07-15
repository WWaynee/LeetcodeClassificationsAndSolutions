const int MAXN = 30;
class Solution {
public:
    // dp[i][j]=true表示s[0,i-1]和p[0,j-1]匹配
    bool dp[MAXN][MAXN] = {false};
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp[0][0] = true;
        for (int i = 2; i <= n;i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    // 跟前一个字符是否匹配
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 2];
                    } else { // 也可以是0次匹配
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[m][n];
    }
};