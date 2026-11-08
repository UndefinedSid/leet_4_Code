class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        vector<int> prefRow(row,0);
        vector<int> prefCol(col,0);
        int ones=0;
        int ans=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    prefRow[i]++;
                    prefCol[j]++;
                }

            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j < col;j++){
                if(grid[i][j]==1){
                    if(prefRow[i] > 1 || prefCol[j] > 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};