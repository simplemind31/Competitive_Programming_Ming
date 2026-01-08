class Solution:
    def solve(self,pos,cade):
        if len(cade)==1:
            return True
        if pos==len(cade)-1:
            nuecade=self.temp
            self.temp=""
            if self.solve(0,nuecade):
                return True
            self.temp=nuecade
            return False
        for posi in self.par[ord(cade[pos])-65][ord(cade[pos+1])-65]:
            self.temp+=chr(posi+65)
            if self.solve(pos+1,cade):
                return True
            self.temp=self.temp[0:len(self.temp)-1]
        return False
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        self.par=[[[] for _ in range(6)] for _ in range(6)]
        self.temp=""
        for i in allowed:
            self.par[ord(i[0])-65][ord(i[1])-65].append(ord(i[2])-65)
        return self.solve(0,bottom)