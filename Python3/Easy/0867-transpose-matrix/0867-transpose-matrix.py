class Solution:
    def transpose(self, matrix: list[list[int]]) -> list[list[int]]:
        row=len(matrix)
        col=len(matrix[0])
        arr=[[0] * row for _ in range(col)]

        for r in range(row):
            for c in range(col):
                arr[c][r]=matrix[r][c]

        return arr