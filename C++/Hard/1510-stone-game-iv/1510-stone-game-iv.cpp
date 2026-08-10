class Solution {
public:
/* Top down (Recursion + Memo) approach 
    // T.C -> O(n * sqrt(n))

    int dp[100001];
    bool finder(int n){
        if(n==0)
            return false;
            
        if(dp[n]!=-1)
            return dp[n];

        for(int i=1;i * i <=n;i++){
            if(finder(n - (i*i))==false)
                return dp[n]=true;
        }
        return dp[n]=false;
    }

    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return finder(n);
    }

    */

    // Bottom Up approach

    bool winnerSquareGame(int n){
        vector<bool> dp(n+1,false);

        for(int i=1;i<n+1;i++){
            for(int j=1;j*j <=i;j++){
                if(dp[i-(j*j)]==false){
                    dp[i]=true;
                    break;
                }

            }
        }
        return dp[n];

    }
};