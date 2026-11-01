class Solution {
public:
    using ll=long long;

    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int mini=nums[0];
        int maxi=nums[n-1];

        if(mini==maxi)
            return 0;

        ll diff=maxi-mini;

        if(n==2)
            return diff;
        else if(diff==n-1)
            return n;
        else{
            ll ops=0;
            for(int i=0;i<n;i++)
                ops += (nums[i] - mini);

            return ops;
        }
           // return (diff * 2 + n);

        return 0;
    }
};