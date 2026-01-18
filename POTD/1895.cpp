---
https://leetcode.com/problems/largest-magic-square/description/?envType=daily-question&envId=2026-01-18
   
## 🧩  PROBLEM --> 1895 (MEDIUM) --> Largest Magic Square - Optimal Prefix Sum Approach
## topics --> Array, Prefix sum, Matrix, Contest

### Problem Overview

The goal is to find the size of the largest **magic square** subgrid within a given  integer matrix.
A magic square is a K * K subgrid where every row, every column, and both main diagonals sum up to the same value.

### 💡 My Approach: Prefix Sum Optimization

Checking every possible subgrid naively can be slow. To optimize, I precompute the cumulative sums for both rows and columns:

1. **Row Prefix Sums (`preRow`):** Allows O(1) calculation of any row segment sum.
2. **Column Prefix Sums (`preCol`):** Allows O(1) calculation of any column segment sum.
3. **Search Strategy:** I iterate from the largest possible side length (min(row,col)) down to 2. The first magic square found is guaranteed to be the largest.

### 🚀 Complexity Analysis

* **Time Complexity:O(M * N * min(M,N)), where  and  are dimensions of the grid.
    * Precomputing prefix sums: O(M * N)
    * Nested loops for subgrids: O(M * N * side) Inside, checking diagonals takes O(side)


* **Space Complexity: O(M * N)  to store the two prefix sum matrices.

---

### 💻 The Code

```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // 1. Precompute Row and Column Prefix Sums
        vector<vector<int>> preRow(row, vector<int>(col));
        vector<vector<int>> preCol(row, vector<int>(col));

        for(int i = 0; i < row; i++){
            preRow[i][0] = grid[i][0];
            for(int j = 1; j < col; j++) 
                preRow[i][j] = preRow[i][j-1] + grid[i][j];
        }

        for(int j = 0; j < col; j++){
            preCol[0][j] = grid[0][j];
            for(int i = 1; i < row; i++) 
                preCol[i][j] = preCol[i-1][j] + grid[i][j];
        }

        // 2. Iterate from largest possible side to smallest
        for(int side = min(row, col); side >= 2; side--){
            for(int i = 0; i + side - 1 < row; i++){
                for(int j = 0; j + side - 1 < col; j++){
                    
                    int targetSum = preRow[i][j + side - 1] - (j > 0 ? preRow[i][j - 1] : 0);
                    bool allSame = true;

                    // Check all rows in the subgrid
                    for(int r = i + 1; r < i + side; r++){
                        int rowSum = preRow[r][j + side - 1] - (j > 0 ? preRow[r][j - 1] : 0);
                        if(rowSum != targetSum) { allSame = false; break; }
                    }
                    if(!allSame) continue;

                    // Check all columns in the subgrid
                    for(int c = j; c < j + side; c++){
                        int colSum = preCol[i + side - 1][c] - (i > 0 ? preCol[i - 1][c] : 0);
                        if(colSum != targetSum) { allSame = false; break; }
                    }
                    if(!allSame) continue;

                    // Check both diagonals
                    int diag = 0, antiDiag = 0;
                    for(int k = 0; k < side; k++){
                        diag += grid[i + k][j + k];
                        antiDiag += grid[i + k][j + side - 1 - k];
                    }

                    if(diag == targetSum && antiDiag == targetSum)
                        return side;
                }
            }
        }
        return 1; // Minimum magic square size is 1x1
    }
};

```

### ✨ Key Takeaways

* Using `prefix sums` is a classic technique for subgrid problems.
* Checking the largest side first allows for an early exit, optimizing the average case.
* The 1 * 1 case is always a magic square by definition, serving as our base return.

---
