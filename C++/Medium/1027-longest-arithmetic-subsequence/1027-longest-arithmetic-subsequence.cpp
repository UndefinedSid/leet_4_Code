class Solution {
public:
    int dp[1001][1001];
    int n;

    int finder(int idx,int diff,vector<int>& nums){
        if(dp[idx][diff] != -1)
            return dp[idx][diff];

        int maxi=1;

        for(int k=0;k<idx;k++){
            if(nums[idx]-nums[k]==diff - 500){
                maxi=max(maxi, 1 + finder(k,diff,nums));
            }
        }
        return dp[idx][diff]=maxi;
    }

    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        if(n<=2)
            return n;
            
        memset(dp,-1,sizeof(dp));
        int ans=2;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j] + 500;
                ans=max(ans,1 + finder(j,diff,nums));
            }
        }
        return ans;
    }
};