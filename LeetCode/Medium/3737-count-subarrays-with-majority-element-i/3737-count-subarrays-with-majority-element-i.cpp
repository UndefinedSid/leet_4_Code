class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int sz = n / 2;
        int i = 0, j = 0;
        int cntTarget = 0, ans = 0;

        while (j < n) {
            if (nums[j] == target) {
                cntTarget++;  
            }

            if (cntTarget > (j-i+1)/ 2) {
                ans++;

            }

            if(j==n-1){
                i++;
                j=i;
                cntTarget=0;
            }
            else
                j++;

        }
        return ans;
    }
};