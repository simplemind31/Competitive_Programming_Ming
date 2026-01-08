class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last=1e9
        res=0
        for i in prices:
            if(i>last):
                res+=i-last
            last=i
        return res