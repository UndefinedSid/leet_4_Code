class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans=[]

        def finder(curr : str,open : int,close : int):
            if(len(curr)==2 * n):
                ans.append(curr)
                return

            if(open < n):
                finder(curr + "(", open +1,close)
            if(close < open):
                finder(curr + ")",open,close+1)

        finder("",0,0)
        return ans