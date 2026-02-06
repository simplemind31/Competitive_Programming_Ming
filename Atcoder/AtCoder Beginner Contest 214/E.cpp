#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)return a.first<b.second;
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        pair<int,int> nums[n];
        for(int i=0;i<n;i++)cin >> nums[i].first >> nums[i].second;
        sort(nums,nums+n,cmp);
        set<pair<int,int>> usado;
        usado.insert({-1e9,-1e9});
        usado.insert({(1e9)+7,(1e9)+7});
        bool xd=true;
        for(int i=0;i<n && xd;i++){
            // elegir el mas a la izquierda disponible;
            auto p=usado.upper_bound(make_pair(nums[i].first,1e9));
            p--;
            if(p->second>=nums[i].second){
                xd=false;
            }else{
                auto ne=next(p);
                pair<int,int> now;
                if(p->second<nums[i].first)now={nums[i].first,nums[i].first};
                else now={p->second+1,p->second+1};
                if(now.first==p->second+1){
                    // unir
                    now.first=p->first;
                    usado.erase(p);
                }
                if(now.second+1==ne->first){
                    now.second=ne->second;
                    usado.erase(ne);
                }
                usado.insert(now);
            }
        }
        if(xd)cout << "Yes\n";
        else cout << "No\n";
    }
}