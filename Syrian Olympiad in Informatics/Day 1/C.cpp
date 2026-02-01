#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,con[4],a,tot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> x >> y;
    if(x==0 || y==0){
        cout << n;
        return 0;
    }else if(x==1){
        for(int i=0;i<n;i++){
            cin >> a;
            // tardo a-1
            if(y>=a-1){
                y-=(a-1);
                tot+=a;
            }else{
                // cada
                tot+=y+1;
                y=0;
            }
        }
        cout << tot;
        return 0;
    }else if(n==1){
        cin >> a;
    }
    map<ll,ll> nums;
    while(n--){
        cin >> a;
        nums[a]++;
    }
    // y veces, cada vez x
    map<ll,ll> nue;
    while(!nums.empty() && y){
        auto p=nums.end();
        ll canti=0;
        while(p!=nums.begin() && canti!=x){
            p--;
            if(p->first<=1)break;
            //auto last=p;
            if(p->second+canti<=x){
                canti+=p->second;
                ll mid=p->first/2;
                nue[mid]+=p->second;
                nue[p->first-mid]+=p->second;
                p->second=0;
            }else{
                ll mid=p->first/2;
                nue[mid]+=x-canti;
                nue[p->first-mid]+=x-canti;
                nums[mid]-=x-canti;
                canti=x;
            }
        }
        y--;
        for(auto u:nue){
            nums[u.first]+=u.second;
        }
        nue.clear();
        p=nums.end();
        p--;
        while(p!=nums.begin() && p->second==0){
            p--;
            nums.erase(next(p));
        }
        if(p->second==0)nums.erase(p);
    }
    for(auto u:nums){
        tot+=u.second;
    }
    cout << tot;
}