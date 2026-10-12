class Solution {
public:
    int MOD=1e9+7;
    using ll=long long;

    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(32,0);

        for(int& val : nums){
            for(int i=0;i<32;i++){
                if(val & (1 << i)){
                    freq[i]++;
                }
            } 
        }

        ll ans=0;
        while(k--){
            ll curr=0;
            for(int b=0;b<32;b++){
                if(freq[b] > 0){
                    freq[b]--;

                    curr = (curr | 1 << b);
                }
            }
            ans = (ans + (curr * curr)) % MOD;
        }
        return ans;
    }
};