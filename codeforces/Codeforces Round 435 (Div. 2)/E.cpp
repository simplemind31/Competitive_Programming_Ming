#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
ll suma,a,temp,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    ll nums[m],posi[m-n+1];
    for(int i=0;i<n;i++){
        cin >> a;
        if(i&1)suma-=a;
        else suma+=a;
    }
    for(int i=0;i<m;i++)cin >> nums[i];
    for(int i=0;i<n;i++){
        if(i&1)temp-=nums[i];
        else temp+=nums[i];
    }
    posi[0]=temp;
    for(int i=n;i<m;i++){
        temp-=nums[i-n];
        temp*=-1;
        if(n&1)temp+=nums[i];
        else temp-=nums[i];
        posi[i-n+1]=temp;
    }
    m=m-n+1;
    sort(posi,posi+m);
    int pos=lower_bound(posi,posi+m,suma)-posi;
    ll mini=1e18;
    if(pos<m)mini=min(mini,posi[pos]-suma);
    pos--;
    if(pos>=0)mini=min(mini,suma-posi[pos]);
    cout << mini << '\n';
    while(q--){
        cin >> a >> b >> c;
        if((b-a+1)&1){
            if(b&1)suma+=c;
            else suma-=c;
        }
        pos=lower_bound(posi,posi+m,suma)-posi;
        mini=1e18;
        if(pos<m)mini=min(mini,posi[pos]-suma);
        pos--;
        if(pos>=0)mini=min(mini,suma-posi[pos]);
        cout << mini << '\n';
    }
}