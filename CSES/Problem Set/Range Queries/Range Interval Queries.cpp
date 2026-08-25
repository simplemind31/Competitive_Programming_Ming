#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define LsOne(x) (x)&(-x)
using namespace std;
int n,q;
struct fenwick{
    int tam;
    vector<int> nums;
    int sum(int x){
        int suma=0;
        for(;x;x-=LsOne(x))suma+=nums[x];
        return suma;
    }
    void update(int x){for(;x<=tam;x+=LsOne(x))nums[x]++;}
    fenwick(int x){nums.resize((tam=x)+1);}
};
vector<int> temp,ord;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int nums[n+1],res[q]={0};
    pair<pair<int,int>,pair<int,int>> queries[q];
    fenwick clav(n+1);
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        temp.push_back(nums[i]);
    }
    // los entre l y r menor o igual que b - los entre l y menor que a
    for(int i=0;i<q;i++){
        cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second.first >> queries[i].second.second;
        temp.push_back(queries[i].second.first);
        temp.push_back(queries[i].second.second);
    }
    sort(ALL(temp));
    ord.push_back(temp[0]);
    for(int i=1;i<temp.size();i++)if(temp[i]!=ord.back())ord.push_back(temp[i]);
    vector<int> pos[ord.size()],menor[ord.size()],menorigual[ord.size()];
    for(int i=1;i<=n;i++)pos[nums[i]=lower_bound(ALL(ord),nums[i])-ord.begin()].push_back(i);
    for(int i=0;i<q;i++){
        menor[queries[i].second.first=lower_bound(ALL(ord),queries[i].second.first)-ord.begin()].push_back(i);
        menorigual[queries[i].second.second=lower_bound(ALL(ord),queries[i].second.second)-ord.begin()].push_back(i);
    }
    for(int i=0;i<ord.size();i++){
        for(auto u:menor[i])res[u]-=clav.sum(queries[u].first.second)-clav.sum(queries[u].first.first-1);
        for(auto u:pos[i])clav.update(u);
        for(auto u:menorigual[i])res[u]+=clav.sum(queries[u].first.second)-clav.sum(queries[u].first.first-1);
    }
    for(auto u:res)cout << u << '\n';
}