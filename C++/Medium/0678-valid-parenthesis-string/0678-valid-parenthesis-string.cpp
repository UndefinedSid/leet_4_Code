class Solution {
public:
    int n;
    int dp[101][101];

    bool finder(int i, int open, string& s) {
        bool isValid = false;
        n = s.size();
        if (i == n)
            return open == 0;

        if(dp[i][open] != -1)
            return dp[i][open];


        if (s[i] == '(') {
            isValid = finder(i + 1, open + 1, s);
        } else if (s[i] == ')' && open > 0)
            isValid = finder(i + 1, open - 1, s);
        else if (s[i] == '*') {
            isValid |= finder(i + 1, open + 1, s);
            isValid |= finder(i + 1, open, s);
            if (open > 0)
                isValid |= finder(i + 1, open - 1, s);
        }

        return dp[i][open]=isValid;
    }

    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));

        return finder(0, 0, s);
    }
};