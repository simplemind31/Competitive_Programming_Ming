#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define LsOne(x) x&(-x)
#define MOD 1000000007
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
ll n,now=500001,fenw[1000002],res;
char c;
void update(int a){
    while(a<=1000001){
        fenw[a]++;
        a+=LsOne(a);
    }
}
ll sum(int a){
    ll suma=0;
    while(a>0){
        suma+=fenw[a];
        a-=LsOne(a);
    }
    return suma;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    //-5e5----5e5
    //0->5e5+1;
    //1---1e6+1
    update(now);
    for(int i=0;i<n;i++){
        cin >> c;
        if(c=='A')now++;
        else if(c=='B')now--;
        res+=sum(now-1);
        update(now);
    }
    cout << res;
}
