#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,w,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> w;
        int pad[n+1],dep[n+1],len[n+1],c1[n+1],c2[n+1];
        for(int i=2;i<=n;i++)cin >> pad[i];
        for(int i=2;i<=n;i++)dep[i]=dep[pad[i]]+1;
        for(int i=1;i<=n;i++)len[i]=c1[i]=0;
        for(int i=1;i<=n;i++){
            x=i,y=(i==n?1:i+1);
            while(x!=y){
                if(dep[x]<dep[y])swap(x,y);
                (c1[x]?c2[x]:c1[x])=i,x=pad[x],len[i]++;
            }
        }
        ll sum=0,sur=n;
        for(int i=1;i<n;i++){
            cin >> x >> y;
            sum+=y;
            if((--len[c1[x]])==0)sur--;
            if((--len[c2[x]])==0)sur--;
            cout << 2*sum+sur*(w-sum) << ' ';
        }
        cout << '\n';
    }
}