class Solution {
public:
    vector<vector<int> > v;
    vector<int> vt;
    vector<bool> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        vis = vector<bool>(nums.size(),false);
        dfs(nums);
        return v;
    }
    void dfs(vector<int>& nums){
        if(vt.size()==nums.size()){
            v.push_back(vt);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vt.push_back(nums[i]);
                vis[i] = true;
                dfs(nums);
                vis[i] = false;
                vt.pop_back();
            }
        }
    }
};