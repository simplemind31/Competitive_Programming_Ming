#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pair<int,int> punt[3];
    for(int i=0;i<3;i++)cin >> punt[i].first >> punt[i].second;
    if(punt[0].first==punt[1].first==punt[2].first){
        cout << "1\n";
        cout << punt[0].first << ' ' << min({punt[0].second,punt[1].second,punt[2].second}) << ' ' << punt[0].first << ' ' << max({punt[0].second,punt[1].second,punt[2].second});
        return 0;
    }
    if(punt[0].second==punt[1].second==punt[2].second){
        cout << "1\n";
        cout << min({punt[0].first,punt[1].first,punt[2].first}) << ' ' << punt[0].second << ' ' <<  max({punt[0].first,punt[1].first,punt[2].first}) << ' ' << punt[0].second;
        return 0;
    }
    sort(punt,punt+3);
    vector<pair<pair<int,int>,pair<int,int>>> res;
    res.push_back({punt[0],{punt[1].first,punt[0].second}});
    res.push_back({{punt[1].first,punt[0].second},punt[1]});
    if(punt[2].second>=max(punt[1].second,punt[0].second)){
        res.push_back({{punt[1].first,max(punt[1].second,punt[0].second)},{punt[2].first,max(punt[1].second,punt[0].second)}});
        res.push_back({{punt[2].first,max(punt[1].second,punt[0].second)},punt[2]});
    }else if(punt[2].second<=min(punt[1].second,punt[0].second)){
        res.push_back({{punt[1].first,min(punt[1].second,punt[0].second)},{punt[2].first,min(punt[1].second,punt[0].second)}});
        res.push_back({{punt[2].first,min(punt[1].second,punt[0].second)},punt[2]});
    }else{
        res.push_back({{punt[1].first,punt[2].second},punt[2]});
    }
    for(int i=0;i<res.size();i++){
        if(res[i].first==res[i].second){
            res.erase(res.begin()+i);
            i--;
        }
    }
    cout << res.size() << '\n';
    for(auto u:res)cout << u.first.first << ' ' << u.first.second << ' ' << u.second.first << ' ' << u.second.second << '\n';
}
