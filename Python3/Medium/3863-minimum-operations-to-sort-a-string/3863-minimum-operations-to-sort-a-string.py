class Solution:
    def minOperations(self, s: str) -> int:
        n=len(s)

        sortedd=True
        for i in range(1,n):
            if s[i] < s[i-1]:
                sortedd=False
                break

        if sortedd:
            return 0

        if n==2 and sortedd==False:
            return -1

        minChar=min(s)
        maxChar=max(s)

        if s[0] == minChar or s[n-1] == maxChar:
            return 1

        for i in range(1,n-1):
            if s[i] == minChar or s[i]==maxChar:
                return 2

        return 3