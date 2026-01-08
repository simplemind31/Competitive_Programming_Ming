class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n=len(prices)
        solve=[0 for i in range(n)]
        psum=list(solve)
        solve[0]=strategy[0]*prices[0]
        psum[0]=prices[0]
        for i in range(1,n):
            solve[i]=solve[i-1]+strategy[i]*prices[i]
            psum[i]=psum[i-1]+prices[i]
        maxi=solve[n-1]
        for i in range(n):
            if(i+k>n):
                break
            """
            de 0 a i-1 solve
            de i a i+k/2-1 nada
            de i+k/2 a i+k-1 vender
            de i+k a n-1 solve
            """
            temp=0
            if(i!=0):
                temp+=solve[i-1]
            temp+=psum[i+k-1]-psum[i+k//2-1]+solve[n-1]-solve[i+k-1]
            maxi=max(maxi,temp)
        return maxi
