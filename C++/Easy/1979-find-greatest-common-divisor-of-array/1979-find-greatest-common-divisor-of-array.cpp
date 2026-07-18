class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int val : nums){
            maxi=max(val,maxi);
            mini=min(mini,val);

        }
        return __gcd(maxi,mini);
    }
};