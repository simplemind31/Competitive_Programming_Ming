class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n=len(strs)
        m=len(strs[0])
        self.con=0
        for i in range(0,m):
            for j in range(1,n):
                if(strs[j][i]<strs[j-1][i]):
                    self.con+=1
                    break
        return self.con