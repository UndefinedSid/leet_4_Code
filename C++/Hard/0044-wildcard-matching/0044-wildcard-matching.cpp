class Solution {
public:
    int dp[2001][2001];
    
    int finder(string& s,string& p,int i,int j){
        if(i==s.size() && j==p.size())
            return 1;

        if(j==p.size())
            return 0;

        if(i==s.size()){
            for(int k=j;k<p.size();k++)
                if(p[k] != '*')
                    return 0;

            return 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];


        if(s[i]==p[j] || p[j]== '?')
           return dp[i][j] = finder(s,p,i+1,j+1);
        else if(p[j]== '*')
            return dp[i][j]= finder(s,p,i+1,j) || finder(s,p,i,j+1);

        return dp[i][j]=0;
    }

    bool isMatch(string s, string p) {
       memset(dp,-1,sizeof(dp));

       return finder(s,p,0,0);
    }
};