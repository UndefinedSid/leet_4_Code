class Solution {
public:
    const int MOD=1e9+7;
    int dp[201][201][201];

    int finder(vector<int>& nums,int idx,int gcd1,int gcd2){
        if(idx==nums.size()){
            bool bothNonEmpty=(gcd1 != 0 && gcd2 != 0);
            bool matched=(gcd1==gcd2);

            return (matched && bothNonEmpty) ? 1 : 0;
        }

        if(dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2];

        int skip=finder(nums,idx+1,gcd1,gcd2);
        int seq1=finder(nums,idx+1,__gcd(gcd1,nums[idx]),gcd2);
        int seq2=finder(nums,idx+1,gcd1,__gcd(gcd2,nums[idx]));

        return dp[idx][gcd1][gcd2]=(0LL + skip + seq1 + seq2) % MOD;

    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return finder(nums,0,0,0);
    }
};