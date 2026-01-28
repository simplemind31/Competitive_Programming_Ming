#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,k,q,psum[200002],a,b,psum2[200002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> q;
    while(n--){
        cin >> a >> b;
        psum[a]++;
        psum[++b]--;
    }
    for(int i=1;i<=200000;i++)psum[i]+=psum[i-1];
    for(int i=1;i<=200000;i++)psum2[i]=psum2[i-1]+(psum[i]>=k);
    while(q--){
        cin >> a >> b;
        cout << psum2[b]-psum2[--a] << '\n';
    }
}