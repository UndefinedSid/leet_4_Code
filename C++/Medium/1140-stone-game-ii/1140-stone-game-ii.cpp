class Solution {
public:
    /*
    // Top Down (Recursion + Memo) approach
    // T.C -> O(N^3) and S.C -> O(N^2)

    int n;
    vector<int> suffSum;
    int dp[101][101];

    int finder(int i,int M){
        if(i + 2 * M >= n){
            return suffSum[i];
        }

        if(dp[i][M] != -1)
            return dp[i][M];

        int maxi=0;
        for(int x=1;x<= 2 * M;x++){
            int st=suffSum[i]  - finder(i+x,max(M,x));
            maxi=max(maxi,st);
        }
        return dp[i][M]=maxi;
        
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffSum.resize(n,0);
        memset(dp,-1,sizeof(dp));

        suffSum[n-1]=piles[n-1];

        for(int i=n-2;i>=0;i--){
            suffSum[i]=piles[i] + suffSum[i+1];
        }

        return finder(0,1); 
    }

    */
    // Bottom Up approach with same time and space complexity
    // but less stack overhead due to non recursion..

    int stoneGameII(vector<int>& piles){
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        vector<int> suffSum(n+1,0);

        for(int i=n-1;i>=0;i--){
            suffSum[i]=piles[i] + suffSum[i+1];
        }

        for(int i=n-1;i>=0;i--){
            for(int M=1;M<=n;M++){
                if(i + 2 * M >= n)
                    dp[i][M]=suffSum[i];
                else{
                    for(int x=1;x<= 2 * M ;x++)
                        dp[i][M]=max(dp[i][M],suffSum[i] - dp[i+x][max(M,x)]);
                }
            }
        }
        return dp[0][1];
    }
};