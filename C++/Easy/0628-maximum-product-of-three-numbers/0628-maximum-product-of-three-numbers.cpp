class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
        // brute force approach

        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int ans=1;
        if(nums[n-1] >= 0 || n==3 || nums[0] < 0){
            ans = (nums[0] * nums[1] * nums[2]);   
        }
        else{
            int l=1,r=n-1,neg=0;
            ans=nums[0];
            bool useRight=(nums[r] * nums[r-1] > nums[l] * nums[l+1]);
            while(neg < 2){
                if(useRight)
                    ans *= nums[r--];
                else
                    ans *= nums[l++];

                neg++;
            }
        }
        return ans;
        */

        // optimal approach

        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        int option1=(nums[0] * nums[1] * nums[2]);
        int option2=(nums[0] * nums[n-1] * nums[n-2]);

        int ans =max(option1,option2);
        return ans;
    }
};