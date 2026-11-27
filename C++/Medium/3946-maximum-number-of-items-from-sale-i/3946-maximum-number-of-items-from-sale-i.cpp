class Solution {
public:
    int n;
    int dp[1001][1501];
    int minPrice=INT_MAX;

    int finder(int n,int budget,vector<vector<int>>& items,vector<int>& copies,int minPrice){
        if(n==0)
            return budget/minPrice;

        int price=items[n-1][1];

        if(dp[n][budget] != -1)
            return dp[n][budget];
        
        int take=0;

        if(price <= budget){
            take = 1 + copies[n-1] + finder(n-1,budget-price,items,copies,minPrice);
        }

        int skip=finder(n-1,budget,items,copies,minPrice);

        return dp[n][budget]=max(take,skip);
        
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        vector<int> copies(n,0);

        for(int i=0;i<n;i++){
            int cpy=0;
            minPrice=min(minPrice,items[i][1]);
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;

                if(items[j][0] % items[i][0]==0)
                    cpy++;

            }
            copies[i]=cpy;
        }
        
        memset(dp,-1,sizeof(dp));
        return finder(n,budget,items,copies,minPrice);

    }
};