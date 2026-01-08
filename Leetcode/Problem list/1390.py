import math 
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res=0
        for i in nums:
            con=0
            num=0
            j=2
            j=int(math.sqrt(i))
            if(j*j==i):
                continue
            while(j>1):
                if(i%j==0):
                    num=j
                    con+=1
                    if con>1:
                        break
                j-=1
            if(con==1):
                res+=1+i+num+i//num
        return res