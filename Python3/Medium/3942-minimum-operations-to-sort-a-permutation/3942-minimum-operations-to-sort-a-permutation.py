class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n=len(nums)
        ascCnt,desCnt=0,0

        for i in range(1,n):
            if nums[i]==(nums[i-1] + 1) % n:
                ascCnt +=1
            elif nums[i-1]==(nums[i] + 1) % n:
                desCnt += 1

        if ascCnt == n-1 and nums[0]==0:

            return 0

        if ascCnt== n-1:
            leftRot=n-nums[0]
            rightRot= 3 + nums[n-1]
            return min(leftRot,rightRot)

        if desCnt == n-1:
            leftRot= n - nums[n-1] + 1
            rightRot= (nums[0] + 1) % n + 1
            return min(leftRot,rightRot)

        
        return -1
        
