#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a,b;
pair<ll,ll> pos(ll lim){
    ll l=0,r=n-1;
    while(l<r){
        ll mid=(l+r+1)>>1;
        // si termina (1,n)+(2,n)+...+(mid,n)
        // hay n+(n-1)+(n-2)+...+(n-(mid-1))
        // n*(mid)-(1+2+...+(mid-1))
        // n*mid-(mid-1)*mid/2
        if(n*mid-(mid-1)*mid/2<lim)l=mid;
        else r=mid-1;
    }
    // esta en (mid+1,x)
    lim-=n*l-(l-1)*l/2;
    return {l+1,l+1+lim-1};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll nums[n+1],psum[n+1],supersum[n+1],doblepsum[n+1],supermegasum[n+1];
    nums[0]=psum[0]=doblepsum[0]=supersum[0]=supermegasum[0]=0;
    // psum[i]=nums[1]+nums[2]+...+nums[i];
    // doblepsum[i]=psum[1]+psum[2]+...+psum[i];
    // supersum[i]=(i,i)+(i,i+1),(i,i+2),(i,i+3),...,(i,n)=psum[i]-psum[i-1]+psum[i+1]-psum[i-1]+psum[i+2]-psum[i-1]+psum[i+3]-psum[i-1]+...+psum[n]-psum[i-1]
    // supersum[i]=psum[i]+psum[i+1]+psum[i+2]+...+psum[n]-(n-i+1)*psum[i-1]
    // supersum[i]=doblepsum[n]-doblepsum[i-1]-(n-i+1)*psum[i-1]
    // supermegasum[i]=supersum[1]+supersum[2]+...+supersum[i]
    for(ll i=1;i<=n;i++){
        cin >> nums[i];
        psum[i]=psum[i-1]+nums[i];
        doblepsum[i]=doblepsum[i-1]+psum[i];
    }
    for(ll i=1;i<=n;i++){
        supersum[i]=doblepsum[n]-doblepsum[i-1]-(n-i+1)*psum[i-1];
        supermegasum[i]=supermegasum[i-1]+supersum[i];
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        // descomponerlo
        // cual es la posicion del a?
        pair<ll,ll> posa=pos(a),posb=pos(b);
        //cout << posa.first << ' ' << posa.second << ':' << posb.first << ' ' << posb.second << '\n';
        // está en (mid+1,x)
        if(posa.first==posb.first){
            // solo en el mismo rango
            //(a.f,a.s),(a.f,a.s+1),(a.f,a.s+2),...,(a.f,b.s)
            //psum[a.s]+psum[a.s+1]+...+psum[b.s]-(b.s-a.s+1)*psum[a.f-1];
            //doblesum[b.s]-doblesum[a.s-1]-(b.s-a.s+1)*psum[a.f-1];
            cout << doblepsum[posb.second]-doblepsum[posa.second-1]-(posb.second-posa.second+1)*psum[posa.first-1] << '\n';
            continue;
        }
        ll res=0;
        //(a.f,a.s),(a.f,a.s+1),(a.f,a.s+2),...,(a.f,n)
        //doblesum[n]-doblesum[a.s-1]-(n-a.s+1)*psum[a.f-1];
        res+=doblepsum[n]-doblepsum[posa.second-1]-(n-posa.second+1)*psum[posa.first-1];
        //(b.f,b.f),(b.f.b.f+1),...(b.f,b.s)
        //doblesum[b.s]-doblesum[b.f-1]-(b.s-b.f+1)*psum[b.f-1];
        res+=doblepsum[posb.second]-doblepsum[posb.first-1]-(posb.second-posb.first+1)*psum[posb.first-1];
        posa.first++;
        posb.first--;
        // supersum[a.f]+supersum[a.f+1]+...+supesum[b.f]
        // supermegasum[b.f]-supermegasum[a.f]
        res+=supermegasum[posb.first]-supermegasum[posa.first-1];
        cout << res << '\n';
    }
}