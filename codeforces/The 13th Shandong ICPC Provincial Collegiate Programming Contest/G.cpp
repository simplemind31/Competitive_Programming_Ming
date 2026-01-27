#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        ll res=0;
        cin >> n;
        map<int,vector<int>> cla;
        for(int i=0;i<n;i++){
            cin >> a;
            cla[i-a].push_back(a);
        }
        for(auto u:cla){
            sort(ALL(u.second));
            for(int i=u.second.size()-1;i>0;i-=2){
                if(u.second[i]+u.second[i-1]>0)res+=u.second[i]+u.second[i-1];
                else break;
            }
        }
        cout << res << '\n';
    }
}