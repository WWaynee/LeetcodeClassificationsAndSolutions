class Solution {
public:
    vector<string> v;//保存结果
    vector<int> bits;//保存切割位置
    vector<string> restoreIpAddresses(string s) {
        dfs(0,s);
        return v;
    }
    bool check(string s, int beg, int end){//判断子串是否为合法数字
        if((beg!=end && s[beg]=='0') || end-beg>=3) return false;
        int num = 0;
        for(int i=beg;i<=end;i++){
            num *= 10;
            num += (s[i]-48);
        }
        if(num>255) return false;
        return true;
    }
    void dfs(int idx, string s){
        if(idx>s.size()) return ;
        if(idx==s.size() && bits.size()==4){
            int beg = 0;
            string res = "";
            for(int i=0;i<bits.size();i++){
                res += (s.substr(beg,bits[i]-beg+1) + '.');
                beg = bits[i] + 1;
            }
            res.pop_back();
            v.push_back(res);
        }
        for(int i=idx;i<s.size() && i-idx<3;i++){
            if(check(s,idx,i)){//合法
                bits.push_back(i);
                dfs(i+1,s);
                bits.pop_back();
            }
        }
    }
};