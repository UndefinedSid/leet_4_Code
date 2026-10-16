class Solution:
    def rotateTheBox(self, boxGrid: list[list[str]]) -> list[list[str]]:
        r=len(boxGrid)
        c=len(boxGrid[0])

        for i in range(r):
            reqPos=c-1
            for j in range(c-1,-1,-1):
                if boxGrid[i][j]=='*':
                    reqPos=j-1
                elif boxGrid[i][j]=='#':
                    boxGrid[i][j]='.'
                    boxGrid[i][reqPos]='#'
                    reqPos -= 1

        
        ans=[['.' for _ in range(r)] for _ in range(c)]

        for i in range(r):
            for j in range(c):
                ans[j][r-1-i]=boxGrid[i][j]

        return ans
        