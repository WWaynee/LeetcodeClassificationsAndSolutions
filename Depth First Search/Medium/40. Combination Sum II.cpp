class Solution {
public:
    vector<vector<int> > v;
    vector<int> vt;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,0,candidates,target);
        return v;
    }
    void dfs(int idx, int sum, vector<int>& candidates, int target){
        if(sum==target){
            v.push_back(vt);
            return ;
        }else if(sum>target || idx>=candidates.size()){
            return ;
        }else{
            for(int i=idx;i<candidates.size();i++){
                if((sum + candidates[i] > target) ||
                     (i>idx && candidates[i]==candidates[i-1])) continue;
                vt.push_back(candidates[i]);
                dfs(i+1,sum+candidates[i],candidates,target);
                vt.pop_back();
            }
        }
    }
};