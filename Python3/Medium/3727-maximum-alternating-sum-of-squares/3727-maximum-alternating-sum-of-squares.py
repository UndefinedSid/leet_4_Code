class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums.sort(key=abs)
        n=len(nums)
        i,j=0,n-1
        ans=0

        while(i <= j):
            if i==j:
                ans += nums[j] * nums[j]
                break

            ans = ans + ( nums[j] * nums[j])
            print(ans)
            j -= 1
            ans = ans -( nums[i] * nums[i])
            i += 1

        return ans