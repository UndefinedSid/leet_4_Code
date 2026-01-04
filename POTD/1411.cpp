/*
Problem -->> 1411 (HARD) -->> NO. OF WAYS TO PAINT N * 3 GRID
Topics -->> RECURSION + MEMOIZATION i.e., DP

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors:
Red, Yellow, or Green while making sure that no two adjacent cells have the same color 
(i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, 
return the number of ways you can paint this grid. 
As the answer may grow large, the answer must be computed modulo 10^9 + 7.

n == grid.length
1 <= n <= 5 * 10^3
*/

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<string> states = {
        "RYG", "RGY", "RYR", "RGR",
        "YRG", "YGR", "YGY", "YRY",
        "GRY", "GYR", "GRG", "GYG"
    };

    vector<vector<int>> dp;

    int check(int n, int prev) {
        if (n == 0) return 1;

        if (dp[n][prev] != -1)
            return dp[n][prev];

        int ans = 0;
        string last = states[prev];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev) continue;

            string cur = states[curr];
            bool ok = true;

            for (int col = 0; col < 3; col++) {
                if (cur[col] == last[col]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = (ans + check(n - 1, curr)) % MOD;
            }
        }

        return dp[n][prev] = ans;
    }

    int numOfWays(int n) {
        dp.assign(n, vector<int>(12, -1));

        int ans = 0;
        for (int i = 0; i < 12; i++) {
            ans = (ans + check(n - 1, i)) % MOD;
        }

        return ans;
    }
};

// Time Complexity -->> O(N)  
