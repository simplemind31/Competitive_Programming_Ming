class Solution:
    def check(self, sub:List[List[int]]) -> bool:
        con=[False for i in range(9)]
        for i in range(3):
            suma=0
            for j in range(3):
                if(sub[i][j]>9 or sub[i][j]==0):
                    return False
                suma+=sub[i][j]
                con[sub[i][j]-1]=True
            if(suma!=15):
                return False
            suma=0
            for j in range(3):
                suma+=sub[j][i]
            if(suma!=15):
                return False
        for i in range(9):
            if(not con[i]):
                return False
        if(not(sub[0][0]+sub[1][1]+sub[2][2]==15 and sub[0][2]+sub[1][1]+sub[2][0]==15)):
            return False
        return True
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        conta=0
        for i in range(2,len(grid)):
            for j in range(2,len(grid[0])):
                #i,j lowerright
                nue=[[grid[i-2][j-2],grid[i-2][j-1],grid[i-2][j]],[grid[i-1][j-2],grid[i-1][j-1],grid[i-1][j]],[grid[i][j-2],grid[i][j-1],grid[i][j]]]
                conta+=self.check(nue)
        return conta