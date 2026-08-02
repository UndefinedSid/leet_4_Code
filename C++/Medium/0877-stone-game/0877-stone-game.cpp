class Solution {
public:
    int n;
    int dp[501][501];

    int finder(vector<int>& piles,int i,int j){
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int takeI=piles[i] + min(finder(piles,i+2,j),finder(piles,i+1,j-1));
        int takeJ=piles[j] + min(finder(piles,i,j-2),finder(piles,i+1,j-1));

        return dp[i][j]=max(takeI,takeJ);
    }

    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));

        int total=accumulate(piles.begin(),piles.end(),0);
        int score=finder(piles,0,n-1);

        return score > total / 2;
    }
};