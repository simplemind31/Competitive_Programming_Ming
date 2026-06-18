#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,k,q,ult=-1,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int nums[n+1],pos[n+1];
    nums[0]=0;
    memset(pos,-1,sizeof(pos));
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        if(nums[i]+nums[i-1]<=k)ult=i;
    }
    int iz=ult-1;
    for(int i=ult;i<=n;i++){
        while(iz>=0 && nums[i]+nums[iz]>k)iz--;
        pos[i]=iz;
    }
    //for(int i=1;i<=n;i++)cout << pos[i] << ' ';
    //cout << '\n';
    for(int i=ult+1;i<=n;i++){
        pos[i]=min(pos[i],pos[i-1]-1);
    }
    // todo lo que está al lado izquierdo o igual que ult pueden
    cin >> q;
    while(q--){
        cin >> a >> b;
        if(nums[b]>k){
            cout << 0;
            continue;
        }
        if((b-a+1)&1)b--;
        if(b<=ult || b-a+1<=0){
            cout << 1;
            continue;
        }
        cout << (a<=pos[b]);
    }
}
/*
13
2 2 4 4 5 5 6 8 9 10
0 1 2 3 4 5 6 7 8 9
9 9 8 8 7 7 6 5 3 1
............6 5 3 1

13
2 9 9 9 9 9 10
0 1 2 3 4 5 6
6 0 0 0 0 0 0
6 0 -1 -2 -3 -4
*/
/*
impar -> sobra un elemento -> elemento que sobra siempre es el mayor

1 2 3 4 5 6 7 8 9

x=13
A=

A
1 4 4 6 8 8 10 11
pos
0 1 2 3 4 5 6 7
posmax
. . . . 2 2 0 0
finalpos
. . . . 
. . . . 2 1 0 -1


i (pos[i]=i)>=posmax[i]

pivote
l r
l<=r<=pivote
si r<=pivote -> si se puede


resolver cuando r>pivote
0 1 2 3 4 5 6 7 8 9 10 11
0 0 0 0 0 0 0 1 1 1 1 1 
// 0 1
// 0 0 0 0 0 0 0 0 1
l r
7 10
// medio1=(l+r-1)/2
// medio2=(l+r+1)/2
r=6 -> si
r->6
r=7
x=1
k
1 k
2 k-1
3 k-3
11 6 -> 17
8 1 -> 9


11 1 -> 12
6 8 -> 14
11 1 12
x y x+y

11 x-> 11+x
1 y -> 1+y

1 2 ->s1 3
3 4 ->s2 7
5 6 ->s3 11
7 8 ->s4 15
9 ->s5 9

1 8 ->9
9 2 -> 11
3 7 -> 10
4 5 -> 9
6 ->6

1 8 ->9
2 7 ->9
3 6 ->9
4 5 ->9
9 ->9

*/