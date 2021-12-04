class Solution {
public:
    int countSubstrings(string s) {
        int size = s.length();
        int res = size;
        bool **dp = new bool*[size];
        for(int i=0;i<size;i++) dp[i] = new bool[size];
        //dp[i][j]表示从i~j是否为回文串
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==j) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
        for(int i=size-1;i>=0;i--){
            for(int j=i+1;j<size;j++){
                if(s[i]==s[j]){
                    if(j==i+1 || dp[i+1][j-1]){
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};