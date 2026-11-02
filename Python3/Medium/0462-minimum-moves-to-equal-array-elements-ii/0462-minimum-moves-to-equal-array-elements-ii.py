class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        n=len(nums)
        nums.sort()
        target=nums[n//2]
        ops=0
        for i in range(n):
            ops += abs(target - nums[i])

        return ops