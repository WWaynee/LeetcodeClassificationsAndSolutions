class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 0, down = 0;
        bool up_ = true, down_ = true;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] && down_){
                up++; up_ = true; down_ = false;
            }else if(nums[i]<nums[i-1] && up_){
                down++; down_ = true; up_ = false;
            }
        }
        return up + down + 1;
    }
};