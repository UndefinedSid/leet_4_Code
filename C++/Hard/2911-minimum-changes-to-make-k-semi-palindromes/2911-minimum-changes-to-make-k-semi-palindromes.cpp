class Solution {
    // Top Down (Recursion + Memo) approach
private:
    int n;
    int memo[201][201]; 
    int cost[200][200]; 

    int solve(int idx, int k_left, const string& s) {
        if (k_left == 0) {
            return (idx == n) ? 0 : INT_MAX / 2;
        }

        if (idx == n) {
            return INT_MAX / 2;
        }

        if (memo[idx][k_left] != -1) {
            return memo[idx][k_left];
        }

        int min_changes = INT_MAX / 2;

        for (int next_idx = idx + 2; next_idx <= n - (k_left - 1) * 2; ++next_idx) {
            int current_cost = cost[idx][next_idx - 1];
            int remaining_cost = solve(next_idx, k_left - 1, s);
            min_changes = min(min_changes, current_cost + remaining_cost);
        }

        return memo[idx][k_left] = min_changes;
    }

public:
    int minimumChanges(string s, int k) {
        n = s.size();
        
        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d < n; d++) {
            for (int m = 2 * d; m <= n; m += d) {
                divisors[m].push_back(d);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INT_MAX;
                for (int d : divisors[len]) {
                    int changes = 0;
                    int groupSize = len / d;
                    for (int r = 0; r < d; r++) {
                        int lo = i + r;
                        int hi = i + r + (groupSize - 1) * d;
                        while (lo < hi) {
                            if (s[lo] != s[hi]) changes++;
                            lo += d;
                            hi -= d;
                        }
                    }
                    best = min(best, changes);
                }
                cost[i][j] = best;
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                memo[i][j] = -1;
            }
        }

        return solve(0, k, s);
    }
};