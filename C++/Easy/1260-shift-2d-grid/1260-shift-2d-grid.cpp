class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();

        int total=r * c;
        k=k % total ;

        auto reverse=[&](int i,int j){
            while(i < j){
                swap(grid[i / c][i % c],grid[j/c][j%c]);
                i++;
                j--;
            }
        };

        reverse(0,total-1);
        reverse(0,k-1);
        reverse(k,total-1);

        return grid;
    }
};