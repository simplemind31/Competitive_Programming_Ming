#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    int ante=0;
    while(n--){
        cin >> now;
        if(now-ante>k){
            cout << "No";
            return 0;
        }
        ante=now;
    }
    cout << "Yes";
}