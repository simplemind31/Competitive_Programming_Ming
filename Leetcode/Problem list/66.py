class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i=len(digits)-1
        while(i>=0):
            if(digits[i]<9):
                digits[i]+=1
                break
            digits[i]=0
            i-=1
        res=[]
        if(i==-1):
            res=[1]+digits
        else:
            res=digits
        return res