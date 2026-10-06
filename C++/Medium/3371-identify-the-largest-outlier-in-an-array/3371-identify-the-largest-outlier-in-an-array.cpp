class Solution {
public:
    using ll=long long;

    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        // if(n==3)
        //     return nums[0];

        for(int val : nums){
            sum += val;
            mp[val]++;
        }

        ll ans=INT_MIN;


        for(int val : nums){
            ll out=sum - 2LL * val;

            if(! mp.count(out))
                continue;


            if(out==val){
                if(mp[out] >=2)
                    ans=max(ans,out);
            }else
                ans=max(ans,out);
        }
        return ans;
    }
};