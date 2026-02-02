#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
ll res=4e18,ori;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    cin >> n;
    pair<ll,ll> nums[n];
    for(int i=0;i<n;i++)cin >> nums[i].first >> nums[i].second;
    sort(nums,nums+n);
    // left->right;
    ll ssum[n+1];
    ssum[n]=0;
    ll maxide=-1e12,maxiar=-1e12,miniiz=1e12,miniab=1e12;
    for(int i=n-1;i>=0;i--){
        maxide=max(maxide,nums[i].first);
        miniiz=min(miniiz,nums[i].first);
        maxiar=max(maxiar,nums[i].second);
        miniab=min(miniab,nums[i].second);
        ssum[i]=(maxide-miniiz)*(maxiar-miniab);
    }
    ori=ssum[0];
    maxide=-1e12,maxiar=-1e12,miniiz=1e12,miniab=1e12;
    for(int i=0;i<n;i++){
        maxide=max(maxide,nums[i].first);
        miniiz=min(miniiz,nums[i].first);
        maxiar=max(maxiar,nums[i].second);
        miniab=min(miniab,nums[i].second);
        res=min(res,(maxide-miniiz)*(maxiar-miniab)+ssum[i+1]);
    }
    // ab-> top
    for(int i=0;i<n;i++)swap(nums[i].first,nums[i].second);
    sort(nums,nums+n);
    for(int i=0;i<n;i++)swap(nums[i].first,nums[i].second);
    ssum[n]=0;
    maxide=-1e12,maxiar=-1e12,miniiz=1e12,miniab=1e12;
    for(int i=n-1;i>=0;i--){
        maxide=max(maxide,nums[i].first);
        miniiz=min(miniiz,nums[i].first);
        maxiar=max(maxiar,nums[i].second);
        miniab=min(miniab,nums[i].second);
        ssum[i]=(maxide-miniiz)*(maxiar-miniab);
    }
    maxide=-1e12,maxiar=-1e12,miniiz=1e12,miniab=1e12;
    for(int i=0;i<n;i++){
        maxide=max(maxide,nums[i].first);
        miniiz=min(miniiz,nums[i].first);
        maxiar=max(maxiar,nums[i].second);
        miniab=min(miniab,nums[i].second);
        res=min(res,(maxide-miniiz)*(maxiar-miniab)+ssum[i+1]);
    }
    cout << ori-res;
}