class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        n=len(nums)
        singleSum,doubleSum=0,0

        for i in range(n):
            if nums[i] < 10:
                singleSum += nums[i]
            else:
                doubleSum += nums[i]

        return singleSum != doubleSum
