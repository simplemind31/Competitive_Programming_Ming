#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int res,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin >> n;
    int pad[n],visited[n];
    for(int i=0;i<n;i++){
        cin >> pad[i];
        pad[i]--;
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        now++;
        int po=pad[i];
        while(visited[po]!=now){
            if(visited[po]==0){
                visited[po]=now;
                po=pad[po];
            }else{
                break;
            }
        }
        if(visited[po]!=now)continue;
        res++;
        int po2=pad[po];
        while(po2!=po){
            res++;
            po2=pad[po2];
        }
    }
    cout << res;
}