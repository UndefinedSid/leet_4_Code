class Solution {
public:
/*
    // Top down Approach -> T.C -> O(N)

    int n;
    int dp[100001];

    int finder(int idx,vector<int> pre){
        if(idx==n-1)
            return pre[n-1];

        if(dp[idx] != -1)
            return dp[idx];

        int take=pre[idx] - finder(idx +1,pre);

        int skip=finder(idx +1,pre);

        return dp[idx]=max(take,skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        vector<int> pre(n,0);
        pre[0]=stones[0];

        memset(dp,-1,sizeof(dp));

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1] + stones[i];
        }

        return finder(1,pre);
    }

    */

    // Bottom Up approach-> T.C -> O(N)

    int stoneGameVIII(vector<int>& stones){
        int n=stones.size();
        vector<int> pre(n,0);
        pre[0]=stones[0];

        for(int i=1;i<n;i++){
            pre[i]=stones[i] + pre[i-1];
        }
        
        vector<int> dp(n,0);

        dp[n-1]=pre[n-1];

        for(int j=n-2;j>=1;j--){
            int take=pre[j] - dp[j+1];

            int skip=dp[j+1];

            dp[j]=max(take,skip);
        }
        return dp[1];
    }

};