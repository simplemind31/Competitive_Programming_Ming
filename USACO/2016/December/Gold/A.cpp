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
    for(int i=0;i<n;i++)cin >> nums[i].first >> nums[i].second;
    int l=0,r=1e9;
    while(l<r){
        int mid=(l+r)>>1;
        for(int i=0;i<n;i++)tam[dsu[i]=i]=1;
        
    }
}