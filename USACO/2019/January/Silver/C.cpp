#include <bits/stdc++.h>
using namespace std;
int n,a,b,con,maxi=-2000000007;
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first)return x.second>y.second;
    return x.first<y.first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    cin >> n;
    pair<int,int> nums[n];
    for(int i=0;i<n;i++){
        cin >> a >> b;
        nums[i]={a-b,a+b};
    }
    sort(nums,nums+n,cmp);
    for(int i=0;i<n;i++){
        //cout << nums[i].first << ' ' << nums[i].second << '\n';
        if(nums[i].second>maxi){
            maxi=nums[i].second;
            con++;
        }
    }
    cout << con;
}
