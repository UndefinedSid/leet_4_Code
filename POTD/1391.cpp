Problem link --> "https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/?envType=daily-question&envId=2026-04-27"

class Solution {
public:
    int row, col;
    unordered_map<int, vector<vector<int>>> dir = {
        {1, {{0,-1},{0,1}}},
        {2, {{-1,0},{1,0}}},
        {3, {{0,-1},{1,0}}},
        {4, {{0,1},{1,0}}},
        {5, {{0,-1},{-1,0}}},
        {6, {{-1,0},{0,1}}}
    };

                // BFS Approach

    // bool hasValidPath(vector<vector<int>>& grid) {
    //     row = grid.size();
    //     col = grid[0].size();

    //     vector<vector<bool>> visit(row, vector<bool>(col, false));
    //     queue<pair<int,int>> q;
    //     q.push({0,0});
    //     visit[0][0] = true;

    //     while(!q.empty()){
    //         auto [i,j] = q.front(); q.pop();
    //         if(i == row-1 && j == col-1) return true;

    //         for(auto& d : dir[grid[i][j]]){
    //             int newI = i + d[0];
    //             int newJ = j + d[1];

    //             if(newI < 0 || newI >= row || newJ < 0 || newJ >= col || visit[newI][newJ])
    //                 continue;

    //             for(auto& backDir : dir[grid[newI][newJ]]){
    //                 if(newI + backDir[0] == i && newJ + backDir[1] == j){
    //                     visit[newI][newJ] = true;
    //                     q.push({newI,newJ});
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }

                    // DFS Approach

    bool dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visit){
        if(i==row-1 && j==col-1)
            return true;

        visit[i][j]=true;

        for(auto& d : dir[grid[i][j]]){
            int newI=i+ d[0];
            int newJ=j+ d[1];

            if(newI < 0 || newI>= row || newJ < 0 || newJ >= col || visit[newI][newJ])
                continue;

            for(auto& backDir : dir[grid[newI][newJ]]){
                if(newI + backDir[0] ==i && newJ + backDir[1]==j)
                    if(dfs(grid,newI,newJ,visit))
                        return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();

        vector<vector<bool>> visit(row,vector<bool>(col,false));
        return dfs(grid,0,0,visit);
    }
};
