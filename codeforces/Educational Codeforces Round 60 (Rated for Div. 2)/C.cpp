#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
ll x1,y,x2,y2,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x1 >> y >> x2 >> y2 >> n;
    pair<ll,ll> move[n+1];
    move[0]={0,0};
    for(ll i=1;i<=n;i++){
        cin >> c;
        move[i]=move[i-1];
        if(c=='U')move[i].second++;
        else if(c=='D')move[i].second--;
        else if(c=='L')move[i].first--;
        else move[i].first++;
    }
    ll l=1,r=1e18;
    while(l<r){
        ll mid=l+((r-l)>>1);
        ll posx=x1+move[n].first*(mid/n)+move[mid%n].first,posy=y+move[n].second*(mid/n)+move[mid%n].second;
        if(abs(posx-x2)+abs(posy-y2)<=mid)r=mid;
        else l=mid+1;
    }
    if(l==1e18)l=-1;
    cout << l;
}