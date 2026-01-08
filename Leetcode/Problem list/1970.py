class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        l=col-1
        r=row*col
        while(l<r):
            mat=[[0 for _ in range(col)] for _ in range(row)]
            visited=list(mat)
            mid=(l+r+1)>>1
            for i in range(mid):
                mat[cells[i][0]-1][cells[i][1]-1]=1
            lol=False
            for i in range(col):
                if(visited[0][i]==0):
                    stack=[]
                    stack.append((0,i))
                    visited[0][i]=1
                    while(len(stack)):
                        top=stack[len(stack)-1]
                        stack.pop()
                        if(top[0]==row-1):
                            lol=True
                            break
                        if(top[0]+1<row):
                            if(visited[top[0]+1][top[1]]==0 and mat[top[0]+1][top[1]]==0):
                                visited[top[0]+1][top[1]]=1
                                stack.append((top[0]+1,top[1]))
                        if(top[0]-1>=0):
                            if(visited[top[0]-1][top[1]]==0 and mat[top[0]-1][top[1]]==0):
                                visited[top[0]-1][top[1]]=1
                                stack.append((top[0]-1,top[1]))
                        if(top[1]+1<col):
                            if(visited[top[0]][top[1]+1]==0 and mat[top[0]][top[1]+1]==0):
                                visited[top[0]][top[1]+1]=1
                                stack.append((top[0],top[1]+1))
                        if(top[1]-1>=0):
                            if(visited[top[0]][top[1]-1]==0 and mat[top[0]][top[1]-1]==0):
                                visited[top[0]][top[1]-1]=1
                                stack.append((top[0],top[1]-1))
                    if lol:
                        break
            if(lol):
                l=mid
            else:
                r=mid-1
        return l