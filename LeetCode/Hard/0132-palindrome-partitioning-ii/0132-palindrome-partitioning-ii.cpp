class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> palin_dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++)
            palin_dp[i][i]=true;

        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;

                if(L==2){
                    palin_dp[i][j]=(s[i]==s[j]);
                }else{
                    palin_dp[i][j]=(s[i]==s[j] && palin_dp[i+1][j-1]);
                }
            }
        }

        vector<int> cut_dp(n,INT_MAX);

        for(int i=0;i<n;i++){
            if(palin_dp[0][i]==true)
                cut_dp[i]=0;
            else{
                for(int k=0;k<i;k++){
                    if(palin_dp[k+1][i]==true && 1 + cut_dp[k] < cut_dp[i])
                        cut_dp[i]=1 + cut_dp[k]; 
                }
            }
        }
        return cut_dp[n-1];
    }
};