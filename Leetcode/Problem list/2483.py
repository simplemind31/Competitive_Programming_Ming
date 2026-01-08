class Solution:
    def bestClosingTime(self, customers: str) -> int:
        res=n=len(customers)
        tot=now=0
        for i in range(n):
            tot+=customers[i]=='Y'
        val=n-tot
        for i in range(n-1,-1,-1):
            now+=customers[i]=='Y'
            if(2*now+i-tot<=val):
                val=2*now+i-tot
                res=i
        return res