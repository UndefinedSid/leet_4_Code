class Solution {
public:
    int row,col;

    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r >= row || r < 0 || c < 0 || c >= col || grid[r][c] == '0')
            return;

        grid[r][c]='0';

        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        if( grid.empty())
            return 0;

        row=grid.size();
        col=grid[0].size();

        int ans=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]== '1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};