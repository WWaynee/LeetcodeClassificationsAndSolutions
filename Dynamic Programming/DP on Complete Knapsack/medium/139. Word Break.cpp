class Solution {
public:
    //因为字典的单词没有限制使用次数，所以是完全背包
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for(int i=1;i<=len;i++){
            //dp[i]=true/false表示字符串的0~i-1子串能否出现在字典里
            for(int j=0;j<i;j++){
                if(set.find(s.substr(j,i-j))!=set.end() && dp[j]) dp[i] = true;
            }
        }
        return dp[len];
    }
};