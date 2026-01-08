class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        i=res=0
        for j in range(m-1,-1,-1):
            while(i<n and grid[i][j]>=0):
                i+=1
            if(i==n):
                break
            res+=n-i
        return res