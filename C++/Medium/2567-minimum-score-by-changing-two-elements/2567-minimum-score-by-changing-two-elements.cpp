class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int twoSmallest,twoLargest,bothEnds;

        for(int val : nums){
            if(n > 3){
               twoSmallest=nums[n-1] - nums[2];
               twoLargest=nums[n-3] - nums[0];
               bothEnds=nums[n-2] - nums[1];
            }else{
                return 0;
            }
        }

        int ans=min({twoSmallest,twoLargest,bothEnds});
        return ans;
    }
};