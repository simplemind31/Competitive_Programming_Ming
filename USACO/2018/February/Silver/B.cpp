#include <bits/stdc++.h>
using namespace std;
int n,b,s,d,now,nums[250],res=1e9;
pair<int,int> boot[251];
bool visited[250][251];
void solve(int pos,int bo){
    if(pos==n-1){
        res=min(res,bo);
        return;
    }
    if(bo>min(b,res-1))return;
    if(visited[pos][bo])return;
    visited[pos][bo]=true;
    if(nums[pos]<=boot[bo].first)for(int i=min(pos+boot[bo].second,n-1);i>pos;i--)if(nums[i]<=boot[bo].first)solve(i,bo);
    solve(pos,bo+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    cin >> n >> b;
    for(int i=0;i<n;i++)cin >> nums[i];
    for(int i=1;i<=b;i++)cin >> boot[i].first >> boot[i].second;
    solve(0,0);
    res--;
    if(res==-1)res=0;
    cout << res;
}