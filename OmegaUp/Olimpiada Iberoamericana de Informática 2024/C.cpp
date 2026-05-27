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