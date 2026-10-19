class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        n=len(nums)
        nums.sort()
        ans=[]

        for i,val in enumerate(nums):
            if val==target:
                ans.append(i)
            elif val > target:
                break

        return ans