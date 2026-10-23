class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        row=len(matrix)
        col=len(matrix[0])
        if not row or not col:
            return []

        ans=[]
        top,bot=0,row-1
        le,ri=0,col-1

        while top <= bot and le <= ri:
            for c in range(le,ri+1):
                ans.append(matrix[top][c])

            top += 1

            for r in range(top,bot+1):
                ans.append(matrix[r][ri])

            ri -= 1

            if top <= bot:
                for c in range(ri,le-1,-1):
                    ans.append(matrix[bot][c])
                bot -= 1

            if le <= ri:
                for r in range(bot,top-1,-1):
                    ans.append(matrix[r][le])
                le += 1

        return ans
