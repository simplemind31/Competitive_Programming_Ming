#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,maxi=0,canposi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // supon la respuesta esta entre i,j
    // cambiar k peores de cada rango por k mejores
    cin >> n >> k;
    ll nums[n],psum[n];
    pair<ll,ll> ord[n];
    for(ll i=0;i<n;i++){
        cin >> nums[i];
        ord[i]={nums[i],i};
    }
    sort(ord,ord+n);
    reverse(ord,ord+n);
    psum[0]=ord[0].first;
    for(int i=1;i<n;i++){
        psum[i]=psum[i-1]+ord[i].first;
    }
    for(int i=0;i<k;i++){
        maxi=max(maxi,psum[i]);
    }
    for(ll i=0;i<n;i++){
        ll suma=0;
        vector<bool> usado(n);
        vector<ll> exis;
        for(ll j=i;j<n;j++){
            // los k peores fuera
            usado[j]=true;
            suma+=nums[j];
            maxi=max(maxi,suma);
            exis.push_back(nums[j]);
            ll pos=exis.size()-1;
            while(pos>0){
                if(exis[pos]<exis[pos-1])swap(exis[pos],exis[pos-1]);
                else break;
                pos--;
            }
            ll sumanue=suma;
            ll l=0,poss=0;
            while(l<k && poss<n && l<exis.size()){
                if(usado[ord[poss].second])poss++;
                else{
                    sumanue+=ord[poss].first;
                    sumanue-=exis[l];
                    maxi=max(maxi,sumanue);
                    l++;
                    poss++;
                }
            }
        }
    }
    cout << maxi;
}