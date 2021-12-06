class Solution {
public:
    vector<vector<int> > v;
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> s;
        v.push_back(s);
        for(int i=0;i<nums.size();i++){
            int size = v.size();
            for(int j=0;j<size;j++){
                vector<int> tmp(v[j]);
                v[j].push_back(nums[i]);
                v.push_back(tmp);
            }
        }
        return v;
    }
};