class Solution {
public:
    int dp[21][21];

    int finder(string& s,string& p,int i,int j){
        if(i==s.size() && j==p.size())
            return 1;

        if(j==p.size())
            return 0;


        if(dp[i][j] != -1)
            return dp[i][j];

        bool matched=( i < s.size() && (s[i]==p[j] || p[j]== '.'));

        if(j + 1 < p.size() && p[j+1] == '*'){
            return dp[i][j]=finder(s,p,i,j + 2) || (matched && finder(s,p,i+1,j));
        }

        return dp[i][j]=(matched && finder(s,p,i+1,j+1));
    }

    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));

        return finder(s,p,0,0);
    }
};