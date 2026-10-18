class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD=10 ** 9 + 7

        def dfs(arr):
            if len(arr) <=2:
                return 1

            root=arr[0]

            left=[x for x in arr[1:] if x < root]
            right=[y for y in arr[1:] if y > root]

            leftWays=dfs(left)
            rightWays=dfs(right)

            comb=math.comb(len(left) + len(right), len(left))

            return (comb * leftWays * rightWays) 

        return (dfs(nums) - 1 + MOD) % MOD

