class Solution:
    def findNumbers(self, nums: list[int]) -> int:
        n=len(nums)
        ans=0

        for i in range(n):
            temp=nums[i]
            cnt=0
            if temp < 10:
                continue
            else:
                while temp > 0:
                    temp //= 10
                    cnt += 1

                if cnt % 2 == 0:
                    ans += 1
        
        return ans