class Solution {
public:
    using ll=long long;
    ll countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cumSum=0;
        ll leftCnt=0,ans=0;

        unordered_map<ll,int> mp;
        mp[0]=1;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                leftCnt += mp[cumSum];
                cumSum++;
            }else{
                cumSum--;
                leftCnt -= mp[cumSum];
            }
            mp[cumSum]++;
            ans += leftCnt;
        }
        return ans;
    }
};