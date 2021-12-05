class Solution {
public:
    vector<vector<string> > v;
    vector<string> vt;
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return v;
    }
    bool check(int begin,int end,string s){
        while(begin<end){
            if(s[begin]==s[end]){
                begin++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
    void dfs(int idx, string s){
        if(idx>=s.size()){
            if(vt.size()!=0) v.push_back(vt);
            return ;
        }else{
            //从idx开始找回文串
            for(int i=idx;i<s.size();i++){
                if(check(idx,i,s)){
                    vt.push_back(s.substr(idx,i-idx+1));
                    dfs(i+1,s);
                    vt.pop_back();
                }
            }
        }
    }
};