"""
dp[i][j]
minimum  si el ultimo usado es i y uso j
caso base todo dp[i][i]=i
dp[i][j]=min(dp[i]+cantidad>strs[j] y <= entre i y j})
dp1[i] minimum si uso i
dp1[j]=min(dp[i][j])
"""
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n=len(strs)
        m=len(strs[0])
        dp1=[1e9 for _ in range(m)]
        dp=[list(dp1) for _ in range(m)]
        for i in range(m):
            dp[i][i]=i
            dp1[i]=i
        for i in range(1,m):
            for j in range(i):
                xd=True
                # checkear si podemos usar j,i
                for k in range(n):
                    if(strs[k][j]>strs[k][i]):
                        xd=False
                        break
                if(xd):
                    dp[j][i]=min(dp[j][i],dp1[j]+(i-1)-(j+1)+1)
                dp1[i]=min(dp1[i],dp[j][i])
        res=1e9
        for i in range(m):
            res=min(res,dp1[i]+(m-1)-(i+1)+1)
        return res