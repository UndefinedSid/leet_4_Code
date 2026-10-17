class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ans=[]
        n=len(nums)

        for i in range(n):
            val=nums[i]
            sum=0
            while val > 0:
                sum += val % 10
                val //= 10
            
            ans.append((sum,nums[i]))


        sortedAns=sorted(ans)
        afterSorted=[pair[1] for pair in sortedAns]

        valIdx={}

        for i in range(n):
            valIdx[nums[i]]=i

        ops=0
        for i in range(n):
            expectedVal=afterSorted[i]
            currVal=nums[i]

            if expectedVal == currVal:
                continue

            idx=valIdx[expectedVal]

            nums[i]=expectedVal
            nums[idx]=currVal

            valIdx[expectedVal]=i
            valIdx[currVal]=idx

            ops += 1

        return ops

        