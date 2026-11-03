class Solution:
    def minMoves(self, nums: List[int]) -> int:
        n=len(nums)
        ops=0
        nums.sort()
        maxi=max(nums)

        for i in range(n):
            ops += (maxi - nums[i])

        return ops