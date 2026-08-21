class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }

    ll finder(ll mid, const vector<int>& coins) {
        int n = coins.size();
        ll cnt = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            ll current_lcm = 1;
            int bit_count = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > mid) break; 
                }
            }

            if (current_lcm <= mid) {
                if (bit_count % 2 == 1) {
                    cnt += mid / current_lcm; 
                } else {
                    cnt -= mid / current_lcm; 
                }
            }
        }
        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        ll st = 1;  
        ll min_coin = *min_element(coins.begin(), coins.end());
        ll end = min_coin * k;
        ll ans = -1;

        while (st <= end) {
            ll mid = st + (end - st) / 2;
            if (finder(mid, coins) >= k) {
                ans = mid;
                end = mid - 1; 
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};