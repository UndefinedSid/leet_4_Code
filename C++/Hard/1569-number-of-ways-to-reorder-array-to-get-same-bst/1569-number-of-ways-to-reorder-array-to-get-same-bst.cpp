class Solution {
public:
    using ll=long long;
    int MOD=1e9 + 7;
    ll combi[1001][1001];
    
    ll dfs(vector<int>& arr){
        if(arr.size() <= 2)
            return 1;

        int root=arr[0];

        vector<int> left,right;

        for(int i=1;i<arr.size();i++){
            if(arr[i] < root)
                left.push_back(arr[i]);
            else if(arr[i] > root)
                right.push_back(arr[i]);
        }

        ll leftWays=dfs(left);
        ll rightWays=dfs(right);

        int n=left.size() + right.size();
        int k=left.size();

       ll comb=combi[n][k];

       ll ans=(comb * leftWays) % MOD;
       ans=( ans * rightWays) % MOD;

       return ans;

    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();

        memset(combi,0,sizeof(combi));
        
        for(int i=0;i<=n;i++){
            combi[i][0]=1;
            for(int j=1;j<=i;j++){
                combi[i][j]=(combi[i-1][j-1] + combi[i-1][j]) % MOD;
            }
        }

        return (dfs(nums) -1 + MOD ) % MOD;
    }
};