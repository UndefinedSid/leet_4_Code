class Solution {
public:
    int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n, 0);
        pref[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        long long ans = 0;
        int oddCnt=0,evenCnt=1;

        for (int i = 0; i < n; i++) {
            if (pref[i] % 2 != 0) {
                ans = (ans + evenCnt) % MOD;
                oddCnt++;
            }else{
                ans = (ans + oddCnt) % MOD;
                evenCnt++;
            }
        }
        return ans;
    }
};