class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        dp = [set() for _ in range(n)]
        dp[0].add(grid[0][0])
        
        for i in range(m):
            next_dp = [set() for _ in range(n)]
            for j in range(n):
                if i > 0: 
                    for val in dp[j]:
                        next_dp[j].add(val ^ grid[i][j])
                
                if j > 0: 
                    for val in next_dp[j - 1]:
                        next_dp[j].add(val ^ grid[i][j])
                        
                if i == 0 and j == 0:
                    next_dp[0].add(grid[0][0])
                    
            dp = next_dp
            
        return min(dp[n - 1])