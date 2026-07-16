class Solution {
public:
    using ll=long long;
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> preGcd(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            preGcd[i]=__gcd(nums[i],maxi);
        }

        ll ans=0;
        sort(preGcd.begin(),preGcd.end());
        int l=0,r=n-1;
        while(l < r){
            ll val=__gcd(preGcd[l],preGcd[r]);
            ans += val;
            l++; r--;
        }
        return ans;
    }
};