#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll res=0;
int exis[300000];
int n,l,pos,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l;
    if(l%3){
        cout << 0;
        return 0;
    }
    exis[0]++;
    for(int i=0;i<n-1;i++){
        cin >> a;
        exis[pos=(pos+a)%l]++;
    }
    for(int i=0;i<l/3;i++){
        res+=1LL*exis[i]*exis[i+l/3]*exis[i+2*l/3];
    }
    cout << res;
}