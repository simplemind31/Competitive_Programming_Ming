#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int t,n;
ll res,suma;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        map<int,int> con;
        con[res=suma=0]++;
        for(int i=1;i<=n;i++){
            cin >> c;
            res+=con[i-(suma+=c-'0')]++;
        }
        cout << res << '\n';
    }
}