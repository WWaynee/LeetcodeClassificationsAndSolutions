# include <climits>
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int size = cuts.size();
        vector<vector<int> > dp(size,vector<int>(size,0));
        for(int gap=2;gap<size;gap++){//间隔
            for(int i=0;i+gap<size;i++){//左界限
                int j = i+gap;//右界限
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<j;k++){
                    dp[i][j] = min(dp[i][j],
                        dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][size-1];
    }
};