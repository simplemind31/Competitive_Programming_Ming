#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define sq(x) (x)*(x)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
struct dsu{
    vector<int> pad,tam;
    int find(int x){return x==pad[x]?x:pad[x]=find(pad[x]);}
    bool unite(int x,int y){
        if((x=find(x))==(y=find(y)))return false;
        if(tam[x]<tam[y])swap(x,y);
        tam[pad[y]=x]+=tam[y];
        return true;
    }
    dsu(int x){
        pad.resize(x);
        tam.resize(x);
        for(int i=0;i<x;i++)tam[pad[i]=i]=1;
    }
};
int n,a,b,can[11];
vector<ll> nums[11];
ll res;
int corres(int x,int y){return x==0?y:can[x-1]+y;}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    dsu clav(n);
    vector<pair<ll,pair<int,int>>> ed;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        nums[b].push_back(a);
    }
    for(int i=0;i<=10;i++)sort(ALL(nums[i]));
    can[0]=nums[0].size();
    for(int i=1;i<=10;i++)can[i]=can[i-1]+nums[i].size();
    for(int i=0;i<=10;i++){
        for(int j=0;j<nums[i].size();j++){
            if(j+1<nums[i].size())ed.push_back({sq(nums[i][j+1]-nums[i][j]),{corres(i,j),corres(i,j+1)}});
            for(int k=0;k<=10;k++){
                if(i==k)continue;
                int pos=lower_bound(ALL(nums[k]),nums[i][j])-nums[k].begin();
                if(pos==nums[k].size())continue;
                ed.push_back({sq(nums[k][pos]-nums[i][j])+sq(k-i),{corres(i,j),corres(k,pos)}});
            }
        }
    }
    sort(ALL(ed));
    for(auto u:ed){
        if(clav.unite(u.second.first,u.second.second))res+=u.first;
    }
    cout << res;
}