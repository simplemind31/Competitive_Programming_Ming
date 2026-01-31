#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,nums[200000],a,t;
vector<ll> col[200000];
ll sumcol[200000],sumtot,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=0;i<200000;i++)col[i].push_back(0);
    for(int i=0;i<n;i++){
        cin >> a;
        a--;
        col[a].push_back(col[a].back()+nums[i]);
    }
    cin >> q;
    while(q--){
        cin >> t >> x >> y;
        x--;
        if(t==1){
            sumtot+=y;
            sumcol[x]+=y;
        }else{
            int l=0,r=col[x].size()-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(col[x][mid]+(sumtot-sumcol[x])*mid<=y)l=mid;
                else r=mid-1;
            }
            cout << l << '\n';
        }
    }
}