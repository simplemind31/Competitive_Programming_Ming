#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll n,resp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<ll,ll>> nums(n);
    vector<pair<ll,ll>> nue;
    for(ll i=0;i<n;i++){
        cin >> nums[i].first;
    }
    for(ll i=0;i<n;i++){
        cin >> nums[i].second;
    }
    ll sum=nums[0].second;
    nue.push_back({0,0});
    for(int i=1;i<n;i++){
        if(nums[i].first==nums[i-1].first){
            sum+=nums[i].second;
        }else{
            nue.push_back({nums[i-1].first,sum});
            sum=nums[i].second;
        }
    }
    nue.push_back({nums[n-1].first,sum});
    nue.push_back({0,0});
    n=nue.size()-2;
    nums=nue;
    set<vector<ll>> ayudaa;
    vector<pair<int,int>> ord(n);
    vector<int> cabe(n+2),cola(n+2);
    vector<bool> usado(n+2);
    cabe[0]=cola[0]=0;
    cabe[n+1]=cola[n+1]=n+1;
    ayudaa.insert({0,0,0});
    for(int i=1;i<=n;i++){
        cabe[i]=cola[i]=i;
        ord[i-1]={nums[i].first,i};
        ayudaa.insert({i,nums[i].first,nums[i].second});
    }
    ayudaa.insert({n+1,0,0});
    sort(ord.rbegin(),ord.rend());
    for(int i=0;i<n;i++){
        auto p=ayudaa.lower_bound({ord[i].second,0,0});
        if((*p)[0]!=ord[i].second)continue;
        vector<ll> ahora=*p;
        auto ante=p,desp=p;
        ante--;
        desp++;
        vector<ll> tempoante=*ante;
        vector<ll> tempodesp=*desp;
        if(tempoante[1]>tempodesp[1]){
            //unir iz;
            ayudaa.erase(ante);
            ayudaa.erase(p);
            ll te1,te2;
            if(ahora[2]%2==0){
                te1=((ahora[2]+1)%MOD)*((ahora[2]/2)%MOD);
                te1%=MOD;
            }else{
                te1=(ahora[2]%MOD)*(((ahora[2]+1)/2)%MOD);
                te1%=MOD;
            }
            if((ahora[1]+tempoante[1]+1)%2==0){
                te2=(((ahora[1]+tempoante[1]+1)/2)%MOD)*((ahora[1]-tempoante[1])%MOD);
                te2%=MOD;
            }else{
                te2=((ahora[1]+tempoante[1]+1)%MOD)*(((ahora[1]-tempoante[1])/2)%MOD);
                te2%=MOD;
            }
            resp+=te1*te2;
            resp%=MOD;
            tempoante[2]+=ahora[2];
            tempoante[2]%=MOD;
            ayudaa.insert(tempoante);
        }else if(tempoante[1]<tempodesp[1]){
            //unir de;
            ayudaa.erase(desp);
            ayudaa.erase(p);
            ll te1,te2;
            if(ahora[2]%2==0){
                te1=((ahora[2]+1)%MOD)*((ahora[2]/2)%MOD);
                te1%=MOD;
            }else{
                te1=(ahora[2]%MOD)*(((ahora[2]+1)/2)%MOD);
                te1%=MOD;
            }
            if((ahora[1]+tempodesp[1]+1)%2==0){
                te2=(((ahora[1]+tempodesp[1]+1)/2)%MOD)*((ahora[1]-tempodesp[1])%MOD);
                te2%=MOD;
            }else{
                te2=((ahora[1]+tempodesp[1]+1)%MOD)*(((ahora[1]-tempodesp[1])/2)%MOD);
                te2%=MOD;
            }
            resp+=te1*te2;
            resp%=MOD;
            tempodesp[2]+=ahora[2];
            ayudaa.insert(tempodesp);
        }else{
            //unir ambos
            ayudaa.erase(ante);
            ayudaa.erase(desp);
            ayudaa.erase(p);
            ll te1,te2;
            if(ahora[2]%2==0){
                te1=((ahora[2]+1)%MOD)*((ahora[2]/2)%MOD);
                te1%=MOD;
            }else{
                te1=(ahora[2]%MOD)*(((ahora[2]+1)/2)%MOD);
                te1%=MOD;
            }
            if((ahora[1]+tempoante[1]+1)%2==0){
                te2=(((ahora[1]+tempoante[1]+1)/2)%MOD)*((ahora[1]-tempoante[1])%MOD);
                te2%=MOD;
            }else{
                te2=((ahora[1]+tempoante[1]+1)%MOD)*(((ahora[1]-tempoante[1])/2)%MOD);
                te2%=MOD;
            }
            resp+=te1*te2;
            resp%=MOD;
            tempoante[2]+=ahora[2];
            tempoante[2]+=tempodesp[2];
            tempoante[2]%=MOD;
            ayudaa.insert(tempoante);
        }
    }
    cout << resp;
}