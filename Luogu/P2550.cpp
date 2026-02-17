#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,con,res[8];
bitset<33> pri;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<7;i++){
        cin >> a;
        pri[--a]=true;
    }
    while(n--){
        for(int i=con=0;i<7;i++){
            cin >> a;
            con+=pri[--a];
        }
        res[7-con]++;
    }
    for(int i=0;i<7;i++)cout << res[i] << ' ';
}