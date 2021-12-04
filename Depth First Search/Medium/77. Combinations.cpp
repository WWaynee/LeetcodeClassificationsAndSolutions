class Solution {
public:
    vector<vector<int> > v;
    vector<int> vt;
    vector<vector<int>> combine(int n, int k) {
        dfs(1,k,n);
        return v;
    }
    void dfs(int idx, int k, int n){
        if(vt.size()==k){
            v.push_back(vt);
            return ;
        }else{
            for(int i=idx;i<=n;i++){
                vt.push_back(i);
                dfs(i+1,k,n);
                vt.pop_back();
            }
        }
    }
};