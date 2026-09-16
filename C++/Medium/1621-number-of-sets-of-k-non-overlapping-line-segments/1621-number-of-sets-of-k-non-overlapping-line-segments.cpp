class Solution {
public:
    int MOD=1e9 + 7;
    using ll=long long;
    int dp[1001][1001];

    /* // Recursion + Memo -> O(k * N^2)
        // passed 67/68 testcases & gave TLE for last testcase 


    int finder(int n,int k,int i){
        if(k==0)
            return 1;

        if(i >= n)
            return 0;

         if(dp[k][i] != -1)
            return dp[k][i];

        ll take=0;

        for(int j=i+1;j<n;j++){
            take += finder(n,k-1,j) % MOD;
        }

        ll skip=finder(n,k,i+1) % MOD;

        return dp[k][i]=(skip + take) % MOD;

    }

    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));

        return finder(n,k,0) % MOD;
    }
    */

    // -------------------------------------------------------------------------------------
    // optimal approach by removing inside j for loop by using vector suffixSum
    // T.C -> O(k * N)

    int numberOfSets(int n,int K){
        for(int i=0;i<n;i++)
            dp[0][i]=1;

        for(int k=1;k<=K;k++){
            vector<int> suffSum(n+1,0);
            for(int x=n-1;x>=0;x--){
                suffSum[x]=(suffSum[x+1] + dp[k-1][x]) % MOD;
            }

            for(int i=n-1;i>=0;i--){
                ll take=suffSum[i+1];

                ll skip=dp[k][i+1] % MOD;

                dp[k][i]=(take + skip) % MOD;
            }
        }
        return dp[K][0];
        
    }

};