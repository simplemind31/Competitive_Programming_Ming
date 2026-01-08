class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        sum=con=0
        for i in apple:
            sum+=i
        capacity.sort()
        for i in range(len(capacity)-1,-1,-1):
            sum-=capacity[i]
            con+=1
            if(sum<=0):
                return con