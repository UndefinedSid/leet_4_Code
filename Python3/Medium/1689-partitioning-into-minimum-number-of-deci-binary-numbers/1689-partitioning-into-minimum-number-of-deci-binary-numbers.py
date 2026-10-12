class Solution:
    def minPartitions(self, n: str) -> int:
        cnt=0
        nList=list(n)

        while True:
            allZero=True

            for i in range(len(nList)):
                if nList[i] > '0':
                    nList[i]=chr(ord(nList[i])-1)
                    allZero=False
            
            if allZero:
                break
            
            cnt += 1

        return cnt
