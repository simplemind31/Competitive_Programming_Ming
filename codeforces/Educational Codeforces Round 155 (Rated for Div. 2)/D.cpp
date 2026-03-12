#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 998244353
using namespace std;
typedef long long ll;
int n;
ll res=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n];
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int bit=0;bit<32;bit++){
        pair<pair<ll,ll>,ll> last[2]={{{0,0},-1},{{0,0},-1}};
        bool xd=false;
        ll temp=0;
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<bit)){
                if(last[xd].second==-1){
                    if(!xd){
                        last[xd]={{i+1,(1ll*(i+1)*(i+2)/2)%MOD},i};
                    }else{
                        last[xd]={{i-last[!xd].second,(1ll*(i-last[!xd].second)*(i-last[!xd].second+1)/2)%MOD},i};
                    }
                }else{
                    last[xd]={{i-last[!xd].second+last[xd].first.first,((1ll*(i-last[!xd].second)*(i-last[!xd].second+1)/2)%MOD+last[xd].first.second+(last[xd].first.first*(i-last[xd].second))%MOD)%MOD},i};
                }
                //cout << last[xd].first.first << ' ' << last[xd].first.second << ' ' << last[xd].second << '\n';
                temp=(temp+last[xd].first.second)%MOD;
                xd=!xd;
            }else{
                if(last[!xd].second!=-1){
                    temp=(temp+((i-last[!xd].second)*last[!xd].first.first)%MOD+last[!xd].first.second)%MOD;
                }
            }
        }
        res=(res+(temp<<bit)%MOD)%MOD;
    }
    cout << res;
}