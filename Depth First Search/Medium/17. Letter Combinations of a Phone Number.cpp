class Solution {
public:
    vector<string> v;
    string str = "";
    map<int, string> m;
    vector<string> letterCombinations(string digits) {
        if(digits=="") return v;
        m[2] = "abc";m[3] = "def";m[4] = "ghi";m[5] = "jkl";
        m[6] = "mno";m[7] = "pqrs";m[8] = "tuv";m[9] = "wxyz";
        dfs(0,digits);
        return v;
    }
    void dfs(int idx, string digits){
        if(idx >= digits.size()){
            v.push_back(str);
            return ;
        }else{
            for(int i=0;i<m[digits[idx]-48].size();i++){
                str += m[digits[idx]-48][i];
                dfs(idx+1,digits);
                str.pop_back();
            }
        }
    }
};