class Solution {
public:
    set<vector<int>> s;
    vector<int> vt;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0,nums);
        return vector<vector<int> > (s.begin(),s.end());
    }
    void dfs(int idx, vector<int>& nums){
        if(vt.size()>=2){
            s.insert(vt);
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(vt.empty() || nums[i]>=vt[vt.size()-1]){
                vt.push_back(nums[i]);
                dfs(i+1,nums);
                vt.pop_back();
            }
        }
    }
};