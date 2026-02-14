#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool xd=true;
ll n,m,a,b,c;
pair<ll,ll> val[100000],x;
vector<ll> nums;
vector<pair<ll,ll>> graph[100000];
bitset<100000> visited;
long double res[100000];
bool xfijo;
void dfs(ll node){
    nums.push_back(node);
    visited[node]=true;
    for(auto u:graph[node]){
        pair<ll,ll> deberia={-val[node].first,u.second-val[node].second};
        if(!visited[u.first]){
            val[u.first]=deberia;
            dfs(u.first);
            if(!xd)return;
        }
        if(deberia==val[u.first])continue;
        if(deberia.first==val[u.first].first){
            xd=false;
            return;
        }
        pair<ll,ll> temp={deberia.second-val[u.first].second,val[u.first].first-deberia.first};
        if(temp.second<0){
            temp.first*=-1;
            temp.second*=-1;
        }
        ll mcd=gcd(abs(temp.first),abs(temp.second));
        temp.first/=mcd;
        temp.second/=mcd;
        if(!xfijo)x=temp;
        else{
            if(temp!=x){
                xd=false;
                return;
            }
        }
        xfijo=true;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    for(ll i=0;i<n && xd;i++){
        if(visited[i])continue;
        xfijo=false;
        nums.clear();
        val[i]={1,0};
        dfs(i);
        if(!xfijo){
            vector<ll> ordena;
            for(auto u:nums){
                //cout << val[u].first << ' ' << val[u].second << '\n';
                ordena.push_back(-val[u].second/val[u].first);
            }
            sort(ordena.begin(),ordena.end());
            x={ordena[(ordena.size()-1)/2],1};
        }
        for(auto u:nums){
            res[u]=(long double)val[u].first*x.first/x.second+val[u].second;
        }
    }
    if(!xd){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << fixed << setprecision(12);
    for(ll i=0;i<n;i++)cout << res[i] << ' ';
}