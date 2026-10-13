class Solution:
    def longestMountain(self, arr: list[int]) -> int:
        n=len(arr)

        if n < 3:
            return 0

        i=0
        ans,cnt=0,0

        leftLen=[1] * n
        rightLen=[1] * n
        
        for i in range(1,n):
            if arr[i] > arr[i-1]:
                leftLen[i]=leftLen[i-1] + 1


        for i in range(n-2,-1,-1):
            if arr[i] > arr[i+1]:
                rightLen[i] = rightLen[i+1] + 1


        for i in range(1,n-1):
            if leftLen[i] > 1 and rightLen[i] > 1:
                cnt = leftLen[i] + rightLen[i] - 1
                ans=max(ans,cnt)

        return ans  

    
