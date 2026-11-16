class Solution {
public:
    string digitSum(string s, int k) {

        while (s.size() > k) {
            int n = s.size();
            vector<int> pref(n, 0);
            pref[0] = s[0] - '0';

            for (int i = 1; i < n; i++) {
                int dgt = s[i] - '0';
                pref[i] = pref[i - 1] + dgt;
            }

            string str = "";
            for (int i = k - 1; i < n; i += k) {
                int dgt = (i == k - 1) ? pref[i] : pref[i] - pref[i - k];
                str += to_string(dgt);
            }
            int last=((n / k) * k) - 1;
            if(last < n-1){
                int dgt=pref[n-1] -(last >= 0 ? pref[last] : 0);
                str += to_string(dgt);
            }
            s=str;
        }

        return s;
    }
};