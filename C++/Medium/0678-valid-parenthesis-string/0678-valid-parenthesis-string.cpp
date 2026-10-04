class Solution {
public:
    // Top down Approach-> T.C O(N^2) && S.C O(N^2)

    // int n;
    // int dp[101][101];

    // bool finder(int i, int open, string& s) {
    //     bool isValid = false;
    //     n = s.size();
    //     if (i == n)
    //         return open == 0;

    //     if(dp[i][open] != -1)
    //         return dp[i][open];


    //     if (s[i] == '(') {
    //         isValid = finder(i + 1, open + 1, s);
    //     } else if (s[i] == ')' && open > 0)
    //         isValid = finder(i + 1, open - 1, s);
    //     else if (s[i] == '*') {
    //         isValid |= finder(i + 1, open + 1, s);
    //         isValid |= finder(i + 1, open, s);
    //         if (open > 0)
    //             isValid |= finder(i + 1, open - 1, s);
    //     }

    //     return dp[i][open]=isValid;
    // }

    bool checkValidString(string s) {
        // memset(dp,-1,sizeof(dp));

        // return finder(0, 0, s);

        // Two Pass approach -> T.C (O(N)) 

        int n=s.size();

        int open=0,close=0;

        for(int i=0;i<n;i++){
            if(s[i]== '(' || s[i]=='*')
                open++;
            else 
                open--;

            if(open < 0)
                return false;

        }

        for(int j=n-1;j>=0;j--){
            if(s[j]== ')' || s[j]=='*')
                close++;
            else
                close--;

            if(close < 0)
                return false;
        }
        return true;
    }
};