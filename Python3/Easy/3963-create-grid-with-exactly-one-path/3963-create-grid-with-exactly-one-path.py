class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        row=m
        col=n
        grid=[['#' for _ in range(col)] for _ in range(row)]

        for j in range(col):
            grid[0][j]= '.'

        for i in range(row):
            grid[i][n-1]= '.'

        return ["".join(r) for r in grid]