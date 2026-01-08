class Solution:
    def minDeletionSize(self, alfab: List[str]) -> int:
        i=con=0
        while(i<len(alfab[0])):
            xd=False
            for j in range(1,len(alfab)):
                if(alfab[j-1][:i+1]>alfab[j][:i+1]):
                    xd=True
                    break
            if(xd):
                con+=1
                for j in range(len(alfab)):
                    alfab[j]=alfab[j][:i]+alfab[j][i+1:]
                i-=1
            i+=1
        return con