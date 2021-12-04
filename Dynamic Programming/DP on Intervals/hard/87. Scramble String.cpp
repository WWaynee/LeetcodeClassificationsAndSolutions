class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(n!=s2.length()) return false;
        bool dp[35][35][35] = {0};
        //dp[i][j][len]代表s1[i,i+len-1]和s2[j,j+len-1]互为扰乱字符串
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s1[i]==s2[j]) dp[i][j][1] = true;
        for(int len=2;len<=n;len++){//区间长度
            for(int i=0;i+len<=n;i++){//s1字符串左边界
                for(int j=0;j+len<=n;j++){//s2字符串左边界
                    for(int p=1;p<len;p++){//区间内分割枚举
                        if(dp[i][j][p] && dp[i+p][j+p][len-p]){//区间内无边换的情况
                            dp[i][j][len] = true;
                            break;
                        }
                        if(dp[i][j+len-p][p] && dp[i+p][j][len-p]){//区间内进行了变换的情况
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};