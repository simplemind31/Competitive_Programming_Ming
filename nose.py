n , m = map(int , input().split()) 
nums = list(map(int , input().split()))

ST = [float("inf") for _ in range(4*n)]

def build(node , l , r):
    global nums , ST
    if l == r:
        ST[node] = [nums[l],1]
    else:
        mid = l + (r-l)//2 
        build(2*node , l , mid)
        build(2*node +1 , mid+1 , r)
        if ST[2*node][0] < ST[2*node + 1][0]:
            ST[node] = ST[2*node]
        elif ST[2*node][0] > ST[2*node + 1][0]:    
            ST[node] = ST[2*node + 1]
        else:
            ST[node] = [ST[2*node][0] , ST[2*node][1] + ST[2*node + 1][1]] 
build(1 , 0 , n-1)

def update(node , l , r , ind , val):
    global nums , ST
    if l == r:
        nums[ind] = val
        ST[node] = [val,1]
    else:
        mid = l + (r-l)//2
        if ind <= mid:
            update(2*node , l , mid , ind , val)
        else:
            update(2*node+1 , mid+1 , r ,ind , val)
        if ST[2*node][0] < ST[2*node + 1][0]:
            ST[node] = ST[2*node]
        elif ST[2*node][0] > ST[2*node + 1][0]:    
            ST[node] = ST[2*node + 1]
        else:
            ST[node] = [ST[2*node][0] , ST[2*node][1] + ST[2*node + 1][1]] 
def query(node , l , r , ql ,qr):
    global nums , ST
    if qr < l or r < ql:
        return [float("inf"), 0]
    if ql <= l and r <= qr:
        return ST[node]
    mid = l+(r-l)//2
    left = query(2*node , l , mid , ql ,qr)
    right = query(2*node+1 , mid+1 , r , ql ,qr)
    if left[0] < right[0]:
        return left
    elif right[0] < left[0]:
        return right
    else:
        return [left[0] , left[1] + right[1]]
for _ in range(m):
    ch , x , y = map(int , input().split())
    if ch == 1:
        update(1 , 0 , n-1 , x , y)
    if ch == 2:
        res = query(1 , 0 , n-1 , x , y-1)
        print(res[0] , res[1])