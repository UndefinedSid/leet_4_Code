class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int ans=(nums[0]-1 ) * (nums[1]-1);
        return ans;
    }
};