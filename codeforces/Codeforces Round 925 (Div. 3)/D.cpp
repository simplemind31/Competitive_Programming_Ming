#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,x,y,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        ll res=0;
        map<pair<int,int>,int> con;
        for(int i=0;i<n;i++){
            cin >> a;
            pair<int,int> now={a%x,a%y};
            res+=con[{(x-now.first)%x,now.second}];
            con[now]++;
        }
        cout << res << '\n';
    }
}