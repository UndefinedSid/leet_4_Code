class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> pre(n,0);
        pre[0] = s[0]-'0';

        vector<ll> preNum(n,0);  
         preNum[0] = (s[0] != '0') ? (s[0]-'0') : 0;

        vector<int> nonZero(n,0);  
        nonZero[0] = (s[0] != '0');

        vector<ll> pwr(n+1,0);     
        pwr[0] = 1;
        for(int i=1;i<=n;i++)
             pwr[i] = (pwr[i-1]*10) % MOD;

        for(int i=1;i<n;i++){
            int dgt = s[i]-'0';
            pre[i] = pre[i-1] + dgt;
            nonZero[i] = nonZero[i-1] + (dgt!=0 ? 1 : 0);
            if(dgt!=0)
                preNum[i] = (preNum[i-1]*10 + dgt) % MOD;
            else
                preNum[i] = preNum[i-1];
        }

        vector<int> ans(queries.size());
        for(int j=0;j<queries.size();j++){
            int l = queries[j][0];
            int r = queries[j][1];

            int stCnt = (l==0) ? 0 : nonZero[l-1];
            ll numBefore = (l==0) ? 0 : preNum[l-1];
            int endCnt = nonZero[r];
            int strLen = endCnt - stCnt;

            if(strLen==0){
                ans[j] = 0;
                continue;
            }

            ll numX = (preNum[r] - (numBefore * pwr[strLen]) % MOD + MOD) % MOD;
            ll sum = pre[r] - ((l==0) ? 0 : pre[l-1]);

            ans[j] = (int)((numX * sum) % MOD);
        }
        return ans;
    }
};
