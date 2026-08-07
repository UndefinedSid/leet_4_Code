class Solution {
public:
    using ll = long long;

    string finder(ll req, ll len) {
        string ans;

        for (int i = 9; i >= 2; i--) {
            while (req % i == 0) {
                ans.push_back(i + '0');
                req /= i;
            }
        }

        while (ans.size() < len) {
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string smallestNumber(string num, ll t) {
        int n = num.size();
        ll temp = t;
        for (int pfact : {2, 3, 5, 7}) {
            while (temp % pfact == 0) {
                temp /= pfact;
            }
        }

        if (temp != 1)
            return "-1";

        vector<ll> remFact(n + 1, t);

        for (int i = 0; i < n; i++) {
            int dgt = num[i] - '0';
            if (dgt == 0)
                break;

            remFact[i + 1] = remFact[i] / gcd(remFact[i], (ll)dgt);
        }

        if (remFact[n] == 1)
            return num;

        int zeroPos = num.find('0');
        int zeroIdx = n - 1;

        if (zeroPos != -1)
            zeroIdx = zeroPos;

        for (int i = zeroIdx; i >= 0; i--) {
            ll req = remFact[i];
            int freeSlot = n - 1 - i;

            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {
                ll furtherReq = req / gcd(req, digit);
                string requiredNum = finder(furtherReq, freeSlot);

                if (requiredNum.size() == freeSlot) {
                    return num.substr(0, i) + char(digit + '0') + requiredNum;
                }
            }
        }
        return finder(t,n+1);
    }
};