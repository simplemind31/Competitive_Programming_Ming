import heapq
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        con=[0]*n
        meetings.sort()
        posi=[]
        for i in range(n):
            heapq.heappush(posi,i)
        ocup=[]
        #tiempo,index
        for i in range(len(meetings)):
            while(len(ocup)>0):
                tiempo,inde=heapq.heappop(ocup)
                if(tiempo<=meetings[i][0]):
                    heapq.heappush(posi,inde)
                else:
                    heapq.heappush(ocup,(tiempo,inde))
                    break
            if(len(posi)>0):
                inde=heapq.heappop(posi)
                con[inde]+=1
                heapq.heappush(ocup,(meetings[i][1],inde))
            else:
                tiempo,inde=heapq.heappop(ocup)
                con[inde]+=1
                heapq.heappush(ocup,(tiempo+meetings[i][1]-meetings[i][0],inde))
        maxi=n-1
        for i in range(n-2,-1,-1):
            if(con[i]>=con[maxi]):
                maxi=i
        return maxi