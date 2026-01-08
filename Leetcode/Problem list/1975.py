class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mini=1e6
        suma=0
        con=0
        for i in matrix:
            for j in i:
                if(j<0):
                    con+=1
                    j=-j
                suma+=j
                mini=min(mini,j)
        if(con&1):
            return suma-2*mini
        else:
            return suma