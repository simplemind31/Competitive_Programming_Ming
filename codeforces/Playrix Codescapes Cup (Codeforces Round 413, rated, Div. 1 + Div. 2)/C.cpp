#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
char t;
int n,m,c,d,a,b,both=-1e9,maxicoin,maxidiamon,purocoin=-1e9,purodiamon=-1e9;
int psummaxicoin[100000],psummaxidiamon[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> c >> d;
    vector<pair<int,int>> coin,diamon;
    for(int i=0;i<n;i++){
        cin >> a >> b >> t;
        if(t=='C')coin.push_back({b,a});
        else diamon.push_back({b,a});
    }
    n=coin.size();
    m=diamon.size();
    if(n)sort(ALL(coin));
    if(m)sort(ALL(diamon));
    if(n && m && coin[0].first<=c && diamon[0].first<=d){
        for(auto u:coin){
            if(u.first<=c)maxicoin=max(maxicoin,u.second);
            else break;
        }
        for(auto u:diamon){
            if(u.first<=d)maxidiamon=max(maxidiamon,u.second);
            else break;
        }
        both=maxicoin+maxidiamon;
    }
    if(n)psummaxicoin[0]=coin[0].second;
    if(m)psummaxidiamon[0]=diamon[0].second;
    for(int i=1;i<n;i++)psummaxicoin[i]=max(psummaxicoin[i-1],coin[i].second);
    for(int i=1;i<m;i++)psummaxidiamon[i]=max(psummaxidiamon[i-1],diamon[i].second);
    for(int i=0;i<n;i++){
        int sob=c-coin[i].first;
        if(sob<coin[0].first)break;
        int pos=upper_bound(ALL(coin),make_pair(sob,(int)1e9))-coin.begin()-1;
        pos=min(pos,i-1);
        if(pos<0)continue;
        purocoin=max(purocoin,coin[i].second+psummaxicoin[pos]);
    }
    for(int i=0;i<m;i++){
        int sob=d-diamon[i].first;
        if(sob<diamon[0].first)break;
        int pos=upper_bound(ALL(diamon),make_pair(sob,(int)1e9))-diamon.begin()-1;
        pos=min(pos,i-1);
        if(pos<0)continue;
        purodiamon=max(purodiamon,diamon[i].second+psummaxidiamon[pos]);
    }
    cout << max({both,purocoin,purodiamon,0});
}