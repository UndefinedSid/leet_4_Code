class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> cirArr(2*n);

        for(int i=0;i<2*n;i++){
            cirArr[i]=code[i % n];
        }

        vector<int> pre(2*n+1,0);
        for (int i = 0; i < 2 * n; i++) {
            pre[i+1] = cirArr[i] + pre[i];
        }

        vector<int> ans(n, 0);
        if (k == 0)
            return ans;

        for (int j = 0; j < n; j++) {
            if (k > 0) {
                ans[j]=pre[j+1+k] -pre[j+1];
            } else {
                int absoluteK=abs(k);
                ans[j]=pre[j+n] - pre[j+n-absoluteK];
            }
        }
        return ans;
    }
};