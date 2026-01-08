class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        res=0
        a=[]
        for i in events:
            a.append(i[0])
            a.append(i[1])
        a.sort()
        b=[]
        b.append(a[0])
        for i in range(1,len(a)):
            if(a[i]!=a[i-1]):
                b.append(a[i])
        a=dict({})
        for i,h in enumerate(b):
            a[h]=i
        prefmax=[0]*len(b)
        sufimax=[0]*len(b)
        clave1=[]
        clave2=[]
        for i in range(len(events)):
            clave1.append((a[events[i][0]],events[i][2]))
            clave2.append((a[events[i][1]],events[i][2]))
            res=max(res,events[i][2])
        clave1.sort()
        clave2.sort()
        j=0
        for i in range(len(b)):
            if(i>0):
               prefmax[i]=prefmax[i-1]
            while(j<len(clave2) and clave2[j][0]==i):
                prefmax[i]=max(prefmax[i],clave2[j][1])
                j+=1
        j=len(clave2)-1
        for i in range(len(b)-1,-1,-1):
            if(i<len(b)-1):
                sufimax[i]=sufimax[i+1]
            while(j>=0 and clave1[j][0]==i):
                sufimax[i]=max(sufimax[i],clave1[j][1])
                j-=1
        for i in range(1,len(b)):
            res=max(res,prefmax[i-1]+sufimax[i])
        return res