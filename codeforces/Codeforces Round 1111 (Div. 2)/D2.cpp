#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t=1,n,q,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        // ans es siempre power of 2
        int need=1;
        while(need<=n)need<<=1;
        vector<int> maxi(2*need),mini(2*need,MOD);
        vector<int> canmal(30);
        for(int i=need;i<need+n;i++){
            cin >> maxi[i];
            mini[i]=maxi[i];
        }
        for(int i=need-1;i>0;i--){
            mini[i]=min(mini[2*i],mini[2*i+1]);
            maxi[i]=max(maxi[2*i],maxi[2*i+1]);
        }
        int debe=__builtin_ctz(need);
        for(int i=1;i<2*need;i++){
            if(__builtin_popcount(i)==1)continue;
            // el minimo de este bloque es>= que le mayor del anterior?
            canmal[debe-(31-__builtin_clz(i))]+=(mini[i]<maxi[i-1]);
        }
        for(int i=0;i<30;i++){
            if(canmal[i]==0){
                cout << ((1<<i)>>1) << '\n';
                break;
            }
        }
        while(q--){
            cin >> a >> b;
            // la posicion a cambiamos a
            int now=need+a;
            while(now>0){
                if(__builtin_popcount(now)!=1){
                    canmal[debe-(31-__builtin_clz(now))]-=(mini[now]<maxi[now-1]);
                }
                if(__builtin_popcount(now+1)!=1){
                    canmal[debe-(31-__builtin_clz(now+1))]-=(mini[now+1]<maxi[now]);
                }
                now/=2;
            }
            now=need+a;
            maxi[now]=mini[now]=b;
            if(__builtin_popcount(now)!=1){
                canmal[debe-(31-__builtin_clz(now))]+=(mini[now]<maxi[now-1]);
            }
            if(__builtin_popcount(now+1)!=1){
                canmal[debe-(31-__builtin_clz(now+1))]+=(mini[now+1]<maxi[now]);
            }
            now/=2;
            while(now>0){
                maxi[now]=max(maxi[2*now],maxi[2*now+1]);
                mini[now]=min(mini[2*now],mini[2*now+1]);
                if(__builtin_popcount(now)!=1){
                    canmal[debe-(31-__builtin_clz(now))]+=(mini[now]<maxi[now-1]);
                }
                if(__builtin_popcount(now+1)!=1){
                    canmal[debe-(31-__builtin_clz(now+1))]+=(mini[now+1]<maxi[now]);
                }
                now/=2;
            }
            for(int i=0;i<30;i++){
                if(!canmal[i]){
                    cout << ((1<<i)>>1) << '\n';
                    break;
                }
            }
        }
    }
}
/*
x0
x 1 0->3
xx 3 1->2
xxxx 7 2->1
xxxxxxxx 15 3->0

8=1000 ctz=3
*/