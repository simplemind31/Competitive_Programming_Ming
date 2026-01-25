#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n+2],ord[n];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        ord[i-1]=nums[i];
    }
    sort(ord,ord+n);
    for(int i=1;i<=n;i++){
        nums[i]=lower_bound(ord,ord+n,nums[i])-ord+1;
    }
    nums[0]=0;
    nums[n+1]=n+1;
    set<pair<pair<int,int>,int>> pad;
    pad.insert({{1,n},1});
    for(int i=1;i<=n;i++){
        auto p=--pad.upper_bound({{nums[i],int(1e9)},(int)1e9});
        if(i>1)cout << ord[p->second-1] << ' ';
        if(p->first.first!=nums[i])pad.insert({{p->first.first,nums[i]-1},nums[i]});
        if(p->first.second!=nums[i])pad.insert({{nums[i]+1,p->first.second},nums[i]});
        pad.erase(p);
    }
}