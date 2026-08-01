class Solution {
public:
    int n;
    int dp[22][22];

    int finder(int i,int j,vector<int>& nums){
        if(i > j)
            return 0;
        
        if(i==j)
            return nums[i];

        if(dp[i][j]!=-1)
            return dp[i][j];

        int takeI=nums[i] + min(finder(i+2,j,nums),finder(i+1,j-1,nums));
        int takeJ=nums[j] + min(finder(i,j-2,nums),finder(i+1,j-1,nums));

        return dp[i][j]=max(takeI,takeJ);

    }

    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));

        int total = accumulate(begin(nums), end(nums), 0);
        
        int score1 = finder(0, n-1,nums);
        int score2 = total - score1;
        
        return score1 >= score2;
    }
};