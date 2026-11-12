class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;

        int ans=1;

        int i=0;
        for(int j=1;j<n;j++){
            if(nums[j] <= nums[j-1]){
                i=j;
            }
            ans =max(ans,j-i+1);

        }

        i=0;
        for(int j=1;j<n;j++){
            if(nums[j] >= nums[j-1]){
                i=j;
            }
            ans=max(ans,j-i+1);
        }

        return ans;;
    }
};