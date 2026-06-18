#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    pair<ll,ll> temp[n+2];
    // si tengo varios negativos in a row, puedo unirlos en uno y no empeora la respuesta
    // entonces al final no puede existir negativos in a row,
    // l[i]=l[i]<i el building mas cerca a i tal que h[l[i]]<h[i] && b[l[i]]>=0
    // r[i]=r[i]>i el building mas cerca a i tal que h[r[i]]<h[i] && b[r[i]]>=0
    // dp?
    for(int i=1;i<=n;i++)cin >> temp[i].first;
    for(int i=1;i<=n;i++)cin >> temp[i].second;
    temp[0]={n+1,0};
    temp[n+1]={n+2,0};
    n+=2;
    vector<pair<ll,ll>> build;
    build.push_back(temp[0]);
    for(int i=1;i<n;i++){
        if(temp[i].second>=0 || build.back().second>=0)build.push_back(temp[i]);
        else if(build.back().first>temp[i].first){
            build.pop_back();
            build.push_back(temp[i]);
        }
    }
    n=build.size()-2;
    for(auto u:build)cout << u.first << ' ';
    cout << endl;
    for(auto u:build)cout << u.second << ' ';
    cout << endl;
    /* puedo usar todos los positivos, para cada negativo
    tengo que unirlo con un positivo o dejarlo nomas
    si uno con un positivo, tengo que quitar los positivos en medio
    si no uno, entonces, tengo que quitar el valor
    */
    int l[n+2],r[n+2];
    ll psumabs[n+2];
    memset(psumabs,0,sizeof(psumabs));
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    set<pair<int,int>> mono;
    mono.insert({0,0});
    for(int i=1;i<=n;i++){
        if(build[i].second>=0){
            while(*prev(mono.end())!=make_pair(0,0) && prev(mono.end())->first>build[i].first){
                mono.erase(prev(mono.end()));
            }
            mono.insert({build[i].first,i});
        }
        l[i]=(--mono.lower_bound({build[i].first,0}))->second;
    }
    mono.clear();
    mono.insert({0,n});
    for(int i=n;i>=1;i--){
        if(build[i].second>=0){
            while(*prev(mono.end())!=make_pair(0,n) && prev(mono.end())->first>build[i].first){
                mono.erase(prev(mono.end()));
            }
            mono.insert({build[i].first,i});
        }
        r[i]=(--mono.lower_bound({build[i].first,0}))->second;
    }
    for(int i=1;i<=n;i++)cout << l[i] << ' ';
    cout << endl;
    for(int i=1;i<=n;i++)cout << r[i] << ' ';
    cout << endl;
    vector<int> negaindices;
    for(int i=1;i<=n;i++){
        if(build[i].second<0)negaindices.push_back(i);
        else res+=build[i].second;
    }
    int m=negaindices.size();
    if(m==0){
        cout << res;
        return 0;
    }
    for(int i=1;i<=n;i++)psumabs[i]=psumabs[i-1]+(build[i].second>=0?build[i].second:0);
    ll dp[m][3];//0=no uno, 1=uno con iz, 2=uno con de
    fill(&dp[0][0],&dp[0][0]+3*m,1e18);
    // dp=minima cantidad que tengo que restar del res si considero los primeros i negativos
    dp[0][0]=abs(build[negaindices[0]].second);
    if(l[negaindices[0]]!=0){
        dp[0][1]=psumabs[negaindices[0]]-psumabs[l[negaindices]]
    }
}
/*
11  4  7  2  1   9 10  6 8 12 
 0 -4 40 -8  4 -10 41 12 3  0 
    0  0  0  0   4  4  4 7 
    4  4  4  8   7  7  8 8 
*/