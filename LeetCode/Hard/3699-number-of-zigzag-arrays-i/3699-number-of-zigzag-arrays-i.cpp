class Solution {
public:
    using ll=long long;
    int MOD=1e9 + 7;
    int m,n;
    
    /* Recursion + memo approach-> got TLE
    int dp[2001][2001][2];
    int prefix_dp[2001][2001][2];

    int zigZagArrays(int target, int l, int r) {
        m=r-l+1;
        n=target;
        if(n==1)
            return m;

        memset(dp,-1,sizeof(dp));
        memset(prefix_dp,-1,sizeof(prefix_dp));

        ll  ans=0;

        for(int i=0;i<m;i++){
            ll down=(1LL * i * finder(2,i,0)) % MOD;
            ll up=(1LL * (m-1-i) * finder(2,i,1)) % MOD;

            ans = (ans + down + up ) % MOD;
        }
        return ans;

    }

    int finder(int idx,int prev,int trend){

        if(idx==n)
            return 1;

        if(dp[idx][prev][trend] != -1)
            return dp[idx][prev][trend];

        if(trend==0)
            return dp[idx][prev][trend]=get_preSum(idx+1,prev-1,1);
        else
            return dp[idx][prev][trend]=get_sufSum(idx+1,prev+1,0);
    
    }

    int get_preSum(int idx,int x,int targetTrend){
        if(x < 0)
            return 0;

        if(prefix_dp[idx][x][targetTrend] != -1)
            return prefix_dp[idx][x][targetTrend];

        ll currVal=finder(idx,x,targetTrend);
        ll totalPrefix=(currVal + get_preSum(idx,x-1,targetTrend)) % MOD;

        return prefix_dp[idx][x][targetTrend]=totalPrefix;

    }

    int get_sufSum(int idx,int x,int targetTrend){
        if(x >= m)
            return 0;

        if(prefix_dp[idx][x][targetTrend] != -1)
            return prefix_dp[idx][x][targetTrend];

        ll currVal=finder(idx,x,targetTrend);
        ll totalSuffix=(currVal + get_sufSum(idx,x+1,targetTrend)) % MOD;

        return prefix_dp[idx][x][targetTrend]=totalSuffix;
    }

    */  

    // Bottom-Up approach

    int zigZagArrays(int n, int l, int r) {
        m=r-l+1;
        if(n==1)
            return m;

        vector<ll> downDp(m,0), upDp(m,0);
        vector<ll> nxt_downDp(m,0), nxt_upDp(m,0);
        vector<ll> suff(m,0), pre(m,0);

        for(int x=0;x<m;x++){
            downDp[x]=x;
            upDp[x]=m-1-x;
        }

        for(int i=3;i<=n;i++){

            ll currSum=0;
            for(int x=0;x<m;x++){
                pre[x]=currSum;
                currSum=(currSum + upDp[x] ) % MOD;
            }

            vector<ll> suff(m,0);
            ll currSum1=0;
            for(int x=m-1;x>=0;x--){
                suff[x]=currSum1;
                currSum1=(currSum1 + downDp[x] ) % MOD;
            }

            for(int y=0;y<m;y++){
                nxt_downDp[y]=pre[y];
                nxt_upDp[y]=suff[y];
            }

            downDp.swap(nxt_downDp);
            upDp.swap(nxt_upDp);

        }

        ll  ans=0;

        for(int i=0;i<m;i++)
            ans=(ans + downDp[i] + upDp[i]) % MOD;

       
        return ans;

    }

};