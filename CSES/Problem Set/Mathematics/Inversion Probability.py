from decimal import Decimal, getcontext
getcontext().prec=50
res=Decimal(0)
con=[Decimal(0)]*100
n=int(input())
X=list(map(Decimal,input().split()))
for x in X:
    for j in range(100):res+=con[j]*min(j,x)/x
    for j in range(int(x)):con[j]+=1/x
print(res.quantize(Decimal("0.000001")))