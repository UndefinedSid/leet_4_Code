class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi,mini=0,prices[0]
        for pr in prices:
            maxi=max(maxi,pr - mini)
            mini=min(mini,pr)

        return maxi