class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i=0
        j=0
        n=len(nums)
        cnt=0

        while j < n:
            k=j+1
            while k < n and nums[j]==nums[k]:
                k += 1

            j=k
            nums[i]=nums[j-1]
            i += 1
            cnt += 1
        
        return cnt
