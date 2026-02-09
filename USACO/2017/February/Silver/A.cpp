#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,con,a;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    cin >> c >> n;
    multiset<int> chicken;
    pair<int,int> cows[n];
    for(int i=0;i<c;i++){
        cin >> a;
        chicken.insert(a);
    }
    for(int i=0;i<n;i++)cin >> cows[i].first >> cows[i].second;
    sort(cows,cows+n,cmp);
    for(int i=0;i<n;i++){
        auto p=chicken.lower_bound(cows[i].first);
        if(p==chicken.end() || *p>cows[i].second)continue;
        con++;
        chicken.erase(p);
    }
    cout << con;
}