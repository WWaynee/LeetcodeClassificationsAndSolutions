class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int maxn = 99999;
        int size = stones.size();
        if((size-1)%(k-1)!=0) return -1;
        vector<int> sum(1,0);
        for(int i=0;i<size;i++) sum.push_back(sum[i]+stones[i]);
        int dp[35][35][35];
        for(int i=0;i<35;i++){
            for(int j=0;j<35;j++){
                for(int m=0;m<35;m++)
                    dp[i][j][m] = maxn;
            }
            dp[i][i][1] = 0;
        }
        for(int len=2;len<=size;len++){
            for(int i=0;i+len-1<size;i++){
                int j = i+len-1;
                for(int m=2;m<=k;m++){
                    for(int p=i;p<j;p++){
                        dp[i][j][m] = min(dp[i][j][m],
                            dp[i][p][1]+dp[p+1][j][m-1]);
                    }
                }
                dp[i][j][1] = dp[i][j][k] + sum[j+1] - sum[i];
            }
        }
        return dp[0][size-1][1];
    }
};