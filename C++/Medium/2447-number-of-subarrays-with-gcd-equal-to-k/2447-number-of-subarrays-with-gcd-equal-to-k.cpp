class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currGcd = 0;
            for (int j = i; j < n; j++) {
                currGcd = __gcd(currGcd, nums[j]);

                if (currGcd == k)
                    ans++;

                if (currGcd < k)
                    break;
            }
        }
        return ans;
    }
};