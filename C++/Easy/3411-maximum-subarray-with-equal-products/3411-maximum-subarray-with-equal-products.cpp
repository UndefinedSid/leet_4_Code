class Solution {
public:
    using ll=long long;

    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;

        for(int i=0;i<n;i++){
            ll g=nums[i],l=nums[i];
            ll prod=nums[i];

            for(int j=i+1;j<n;j++){
                g=gcd(g,nums[j]);
                l=(l / gcd(l,nums[j])) * nums[j];
                prod *= nums[j];
                ll rhs=l * g;
                if(prod==rhs){
                    ans=max(ans,j-i+1);
                }

                if(prod > rhs)
                    break;
            }
        }
        return ans;
    }
};