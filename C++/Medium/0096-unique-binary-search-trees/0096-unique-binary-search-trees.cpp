class Solution {
public:

    // Top Down (Rec + Memo) Approach
    // Time comp-> O(N^2) & space-> O(N) 

    int dp[20];

    int finder(int n){
        if(n <= 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans=0;

        for(int i=1;i<=n;i++){
            int leftBst=finder(i-1);
            int rightBst=finder(n-i);

           ans += leftBst * rightBst;
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));

        return finder(n);
    }
};

    // --------------------------------------------------
    /* Bottom Up Approach 
        // T.C -> O(N^2) and Space comp-> O(N)

    int numTrees(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
       
    }
     
};

    */