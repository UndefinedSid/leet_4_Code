class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        n=len(nums)
        arr=[]

        for i,val in enumerate(nums):
            if val != i:
                arr.append(val)

        arrSize=len(arr)

        if arrSize == 0:
            return 0

        arr.sort()
        k=arr[0]

        for i in range(1,arrSize):
            k &= arr[i]


        return k


