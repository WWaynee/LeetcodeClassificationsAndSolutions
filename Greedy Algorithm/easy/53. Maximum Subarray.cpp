class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = 0, maxn = INT_MIN;
        for(int i=0;i<n;i++){
            if(res > 0) res += nums[i];
            else res = nums[i];
            maxn = max(maxn,res);
        }
        return maxn;
    }
};