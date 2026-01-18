#include <bits/stdc++.h>
using namespace std;
bool imposibad[50],existe[50][50];
int n,m,d,s,a,b,c,timesick[50],maxi;
vector<int> peopledrthis[50];
vector<pair<int,int>> person[50];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);
    cin >> n >> m >> d >> s;
    pair<int,pair<int,int>> events[d];
    for(int i=0;i<d;i++)cin >> events[i].second.first >> events[i].second.second >> events[i].first;
    sort(events,events+d);
    for(int i=0;i<d;i++){
        if(existe[--events[i].second.first][--events[i].second.second])continue;
        existe[events[i].second.first][events[i].second.second]=true;
        peopledrthis[events[i].second.second].push_back(events[i].second.first);
        person[events[i].second.first].push_back({events[i].first,events[i].second.second});
    }
    for(int i=0;i<s;i++){
        cin >> a >> b;
        timesick[--a]=b;
    }
    for(int i=0;i<n;i++){
        if(timesick[i]==0)continue;
        vector<bool> posi(m);
        for(int j=0;j<person[i].size() && person[i][j].first<timesick[i];j++)posi[person[i][j].second]=true;
        for(int j=0;j<m;j++)imposibad[j]|=!posi[j];
    }
    for(int i=0;i<m;i++)if(!imposibad[i])maxi=max(maxi,(int)peopledrthis[i].size());
    cout << maxi;
}