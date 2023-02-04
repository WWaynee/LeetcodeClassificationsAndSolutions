class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.length();
        int **dp = new int*[size];
        for(int i=0;i<size;i++) dp[i] = new int[size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==j) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        } 
        for(int i=size-1;i>=0;i--){
            for(int j=i+1;j<size;j++){
                if(j==i+1){
                    if(s[i]==s[j]) dp[i][j] = 2;
                    else dp[i][j] = 1;
                }else{
                    if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                    else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
    }
};