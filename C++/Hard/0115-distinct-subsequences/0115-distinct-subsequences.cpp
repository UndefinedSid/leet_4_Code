class Solution {
public:
    using ll =long long;
    int dp[1001][1001];
    int sizeS, sizeT;

    ll finder(string& s,string& t,int i,int j){
        if(j==sizeT)
            return dp[i][j]=1;
        
        if(i==sizeS)
            return dp[i][j]=0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j]= finder(s,t,i+1,j+1) + finder(s,t,i+1,j);
        }else{
            return dp[i][j]=finder(s,t,i+1,j);
        }
        
        return -1;
    }

    int numDistinct(string s, string t) {
        sizeS=s.size();
        sizeT=t.size();

        memset(dp,-1,sizeof(dp));

        return finder(s,t,0,0);
    }
};