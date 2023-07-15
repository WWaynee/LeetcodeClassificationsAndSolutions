class Solution {
public:
    vector<vector<int> > v;
    vector<int> vt;
    vector<bool> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vis = vector<bool>(nums.size(),false);
        dfs(nums);
        return v;
    }
    void dfs(vector<int>& nums){
        if(vt.size()==nums.size()){
            v.push_back(vt);
            return ;
        }else{
            for(int i=0;i<nums.size();i++){
                if(i>0 && nums[i]==nums[i-1] && vis[i-1]) continue;
                if(!vis[i]){
                    vt.push_back(nums[i]);
                    vis[i] = true;
                    dfs(nums);
                    vis[i] = false;
                    vt.pop_back();
                }
            }
        }
    }
};