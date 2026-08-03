class Solution {
public:
    int n;
    vector<int> dp;

    int finder(vector<int>& stoneValue,int i){
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans=stoneValue[i] - finder(stoneValue,i+1);
        if(i+1 < n)
            ans=max(ans,stoneValue[i] + stoneValue[i+1] - finder(stoneValue,i+2));
        
        if(i +2 < n)
            ans=max(ans,stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - finder(stoneValue,i+3));

        return dp[i]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.resize(n+1,-1);

        int ans=finder(stoneValue,0);

        if(ans > 0)
            return "Alice";
        else if(ans < 0)
            return "Bob";
        else
            return "Tie";

    }
};