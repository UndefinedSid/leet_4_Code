class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        ## optimal (IN-PLACE Cyclic Sort) -> (O(N)) & S.C -> O(1)

        n=len(nums)

        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i]-1] != nums[i]:
                bestIdx=nums[i] - 1
                nums[i],nums[bestIdx]=nums[bestIdx],nums[i]

        for i in range(n):
            if nums[i] != i+1:
                return i+1

        
        return n + 1