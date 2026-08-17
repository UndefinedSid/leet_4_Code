class Solution {
public:

    // TOP DOWN(RECURSION + MEMO)
    int n ;
    int dp[501][501];

    int finder(int l,int r,vector<int>& pre){
        if(l >= r)
            return 0;

        int ans=0;

        if(dp[l][r] != -1)
            return dp[l][r];

        for(int idx=l;idx < r;idx++){
            int lSum=pre[idx]-(l-1 >=0 ? pre[l-1] : 0);
            int rSum=pre[r] - pre[idx];

            if(lSum > rSum){
                ans = max(ans,rSum + finder(idx+1,r,pre));
            }
            else if(lSum < rSum){
                ans =max(ans,lSum + finder(l,idx,pre));
            }else{
                ans=max({ans,lSum + finder(l,idx,pre),rSum + finder(idx+1,r,pre)});
            }
        }
        return dp[l][r]=ans;

    }

    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        if(n==1)
            return 0;

        memset(dp,-1,sizeof(dp));

        vector<int> pre(n);
        pre[0]=stoneValue[0];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1] + stoneValue[i];
        }

        return finder(0,n-1,pre);
    }
};