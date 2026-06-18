#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> p;
        int nums[n];
        pair<int,int> ord[n];
        for(int i=0;i<n;i++){
            cin >> nums[i];
            ord[i]={nums[i],i};
        }
        sort(ord,ord+n);
        vector<pair<pair<int,int>,int>> rangos;
        vector<bool> used(n);
        for(int i=0;i<n;i++){
            if(ord[i].first>=p)break;
            if(used[ord[i].second])continue;
            int iz=ord[i].second,de=iz;
            while(iz>0 && nums[iz-1]%ord[i].first==0)iz--;
            while(de+1<n && nums[de+1]%ord[i].first==0)de++;
            rangos.push_back({{iz,de},ord[i].first});
            for(int j=iz;j<=de;j++)used[j]=true;
        }
        ll res=0,con=0;
        set<pair<int,int>> lr;
        for(auto& u:rangos){
            auto p=lr.lower_bound({u.first.first,0});
            if(p!=lr.begin()){
                auto ante=prev(p);
                if(ante->second>=u.first.first)u.first.first=ante->second;
            }
            if(p!=lr.end()){
                if(p->first<=u.first.second)u.first.second=p->first;
            }
            if(u.first.first>=u.first.second)continue;
            res+=1ll*(u.first.second-u.first.first)*u.second;
            con+=u.first.second-u.first.first;
            lr.insert(u.first);
        }
        res+=1ll*(n-1-con)*p;
        cout << res << '\n';
    }
}