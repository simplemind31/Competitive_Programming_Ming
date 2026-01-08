class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort()
        con=res=0
        for i in range(len(happiness)-1,-1,-1):
            happiness[i]-=con
            if(happiness[i]>0):
                res+=happiness[i]
                con+=1
            else:
                break
            if(con==k):
                break
        return res