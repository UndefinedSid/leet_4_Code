class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        row=len(grid)
        col=len(grid[0])
        dir=[(-1,0),(1,0),(0,-1),(0,1)]

        def dfs(r,c):
            allSum=grid[r][c]
            grid[r][c]=0
            
            for dr,dc in dir:
                nr=r + dr
                nc=c+ dc
                if 0 <= nr < row and 0 <= nc < col and grid[nr][nc] > 0:
                    allSum += dfs(nr,nc)


            return allSum

        ans=0
        for r in range(row):
            for c in range(col):
                if grid[r][c] > 0:
                    allSum=dfs(r,c)
                    if allSum % k==0:
                        ans += 1

        return ans
