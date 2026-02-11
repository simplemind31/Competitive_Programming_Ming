#include <bits/stdc++.h>
using namespace std;
int n,maxi,dsu[1000],tam[1000];
pair<int,int> nums[1000];
int find(int a){return (a==dsu[a])?a:dsu[a]=find(dsu[a]);}
bool unite(int a,int b){
    if((a=find(a))==(b=find(b)))return false;
    if(tam[b]>tam[a])swap(a,b);
    tam[a]+=tam[b];
    dsu[b]=a;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        tam[dsu[i]=i]=1;
        cin >> nums[i].first >> nums[i].second;
    }
    int l=0,r=1e9;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.push_back({pow(nums[i].first-nums[j].first,2)+pow(nums[i].second-nums[j].second,2),{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    for(auto u:edges){
        maxi=u.first;
        n-=unite(u.second.first,u.second.second);
        if(n==1)break;
    }
    cout << maxi;
}