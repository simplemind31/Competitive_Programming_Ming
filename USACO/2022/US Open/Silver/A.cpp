#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int now;
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    pair<int,int> pad[n];
    int visited[n];
    for(int i=0;i<n;i++){
        cin >> pad[i].first >> pad[i].second;
        res+=pad[i].second;
        pad[i].first--;
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        now++;
        int po=pad[i].first;
        while(visited[po]!=now){
            if(visited[po]==0){
                visited[po]=now;
                po=pad[po].first;
            }else{
                break;
            }
        }
        if(visited[po]!=now)continue;
        // restar al minimo del cycle
        int mini=pad[po].second;
        int po2=pad[po].first;
        while(po2!=po){
            mini=min(mini,pad[po2].second);
            po2=pad[po2].first;
        }
        res-=mini;
    }
    cout << res;
}