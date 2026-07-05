class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    bool dp[101][101];
    pair<int,int> memo[101][101];

    pair<int,int> finder(vector<string>& board, int r,int c) {
        if (r==0 && c==0)
            return {0,1};

        if(r < 0 || c < 0 || board[r][c]=='X')
            return {-1,0};

        if (dp[r][c] != false)
            return memo[r][c];

        pair<int,int> takeUp=finder(board,r-1,c);
        pair<int,int> takeDiag=finder(board,r-1,c-1);
        pair<int,int> takeLeft=finder(board,r,c-1);

        int maxi=-1;
        int paths=0;

        maxi=max({takeUp.first,takeDiag.first,takeLeft.first});
 
        if(maxi==-1){
            dp[r][c]=true;
            return memo[r][c]={-1,0};
        }

        if(takeUp.first==maxi)
            paths=(paths + takeUp.second) % MOD;

        if(takeDiag.first==maxi)
            paths=(paths + takeDiag.second) % MOD;

        if(takeLeft.first==maxi)
            paths=(paths + takeLeft.second) % MOD;

        int currVal=(board[r][c]=='S') ? 0 : (board[r][c]-'0');
        maxi += currVal;

        dp[r][c]=true;

        return memo[r][c]={maxi,paths};

    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
       
        memset(dp,false,sizeof(dp));

        pair<int,int> ans=finder(board,n-1,n-1);

        if(ans.first==-1)
            return {0,0};

        return {ans.first,ans.second};
    }
};