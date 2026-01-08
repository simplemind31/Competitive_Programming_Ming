class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini=1e9
        res=0
        for i in prices:
            res=max(i-mini,res)
            mini=min(mini,i)
        return res