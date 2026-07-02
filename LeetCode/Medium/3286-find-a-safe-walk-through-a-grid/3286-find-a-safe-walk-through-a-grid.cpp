class Solution {
public:

    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row=grid.size();
        int col=grid[0].size();

        vector<vector<int>> ans(row,vector<int> (col,INT_MAX));
        deque<pair<int,int>> dq;

        ans[0][0]=grid[0][0];
        dq.push_front({0,0});

        while(! dq.empty()){
            auto [r,c]=dq.front();
            dq.pop_front();

            for(auto& dir : direction){
                int newRow= r + dir[0];
                int newCol=c + dir[1];

                if(newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
                    continue;

                if(ans[r][c] + grid[newRow][newCol] < ans[newRow][newCol]){
                    ans[newRow][newCol]= ans[r][c] + grid[newRow][newCol];

                    if(grid[newRow][newCol]==0)
                        dq.push_front({newRow,newCol});
                    else
                        dq.push_back({newRow,newCol});
                }
                    
            }
        }
        int req=ans[row-1][col-1];

        return (health - req >= 1 );
    }
};