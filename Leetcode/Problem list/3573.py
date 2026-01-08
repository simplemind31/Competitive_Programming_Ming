class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        xd=0
        n=len(prices)
        dp=[[[0 for _ in range(3)] for _ in range(k+1)] for _ in range(2)]
        for j in range(1,k+1):
            dp[0][j][1]=prices[0]
            dp[0][j][2]=-prices[0]
        for i in range(1,n):
            xd=1-xd
            for j in range(1,k+1):
                dp[xd][j][0]=max({dp[1-xd][j][1]-prices[i],dp[1-xd][j][2]+prices[i],dp[1-xd][j][0]})
                dp[xd][j][1]=max(dp[1-xd][j-1][0]+prices[i],dp[1-xd][j][1])
                dp[xd][j][2]=max(dp[1-xd][j-1][0]-prices[i],dp[1-xd][j][2])
        return dp[xd][k][0]
        