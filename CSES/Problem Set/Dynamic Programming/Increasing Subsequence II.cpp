#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LsOne(x) x&(-x)
typedef long long ll;
map<int,int> key;
ll n,now=1,res,temp;
vector<ll> fenw;
ll sum(ll x){
    ll suma=1;
    while(x>0){
        suma+=fenw[x];
        suma%=MOD;
        x-=LsOne(x);
    }
    return suma;
}
void upd(ll x,ll can){
    while(x<now){
        fenw[x]+=can;
        fenw[x]%=MOD;
        x+=LsOne(x);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<int> nums(n),ord(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        ord[i]=nums[i];
    }
    sort(ord.begin(),ord.end());
    key[ord[0]]=now++;
    for(int i=1;i<n;i++)if(ord[i]!=ord[i-1])key[ord[i]]=now++;
    for(int i=0;i<n;i++)nums[i]=key[nums[i]];
    fenw.resize(now);
    for(int i=0;i<n;i++){
        upd(nums[i],temp=sum(nums[i]-1));
        res=(res+temp)%MOD;
    }
    cout << res;
}