class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        sqSumSegTree = [0] * (4 * n)
        sumSegTree = [0] * (4 * n)
        lazyTree = [0] * (4 * n)
        
        def lazyAddition(i: int, l: int, r: int, val: int):
            length = r - l + 1
            sqSumSegTree[i] = (sqSumSegTree[i] + 2 * val * sumSegTree[i] + length * val * val) % MOD
            sumSegTree[i] = (sumSegTree[i] + length * val) % MOD

        def updateRange(start: int, end: int, i: int, l: int, r: int, val: int):
            if lazyTree[i] != 0:
                lazyAddition(i, l, r, lazyTree[i])
                if l != r:
                    lazyTree[2 * i + 1] = (lazyTree[2 * i + 1] + lazyTree[i]) % MOD
                    lazyTree[2 * i + 2] = (lazyTree[2 * i + 2] + lazyTree[i]) % MOD
                lazyTree[i] = 0

            if l > end or r < start or l > r:
                return

            if l >= start and r <= end:
                lazyAddition(i, l, r, val)
                if l != r:
                    lazyTree[2 * i + 1] = (lazyTree[2 * i + 1] + val) % MOD
                    lazyTree[2 * i + 2] = (lazyTree[2 * i + 2] + val) % MOD
                return

            mid = l + (r - l) // 2
            updateRange(start, end, 2 * i + 1, l, mid, val)
            updateRange(start, end, 2 * i + 2, mid + 1, r, val)

            sumSegTree[i] = (sumSegTree[2 * i + 1] + sumSegTree[2 * i + 2]) % MOD
            sqSumSegTree[i] = (sqSumSegTree[2 * i + 1] + sqSumSegTree[2 * i + 2]) % MOD

        max_val = max(nums) if nums else 0
        lastSeenIdx = [-1] * (max(100001, max_val + 1))
        result = 0

        for i in range(n):
            start = lastSeenIdx[nums[i]] + 1
            end = i

            updateRange(start, end, 0, 0, n - 1, 1)

            result = (result + sqSumSegTree[0]) % MOD
            lastSeenIdx[nums[i]] = i

        return result