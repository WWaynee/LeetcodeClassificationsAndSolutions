class Solution {
public:
    //和78题的不同：可能出现重复元素
    //剪枝：在同一个vector中同个位置不能是同个数
    vector<vector<int> > v;
    vector<int> vt;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        v.push_back(vector<int>());
        dfs(0,nums);
        return v;
    }
    void dfs(int idx, vector<int>& nums){
        if(idx>=nums.size()){
            return ;
        }else{
            for(int i=idx;i<nums.size();i++){
                if(i!=idx && nums[i]==nums[i-1]) continue;
                vt.push_back(nums[i]);
                v.push_back(vt);
                dfs(i+1,nums);
                vt.pop_back();
            }
        }
    }
};