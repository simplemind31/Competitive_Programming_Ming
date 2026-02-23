#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MAXN=5000001;
int t,n,res[MAXN],maxmod[4]={2,1,2,3},a;
bitset<MAXN> criba;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    criba[0]=criba[1]=1;
    res[0]=0;
    res[1]=1;
    for(int i=2;i<MAXN;i++){
        if(!criba[i]){
            maxmod[i%4]=i;
            if(i<=3e3)for(int j=i*i;j<MAXN;j+=i)criba[j]=true;
        }
        res[i]=1+(i-maxmod[i%4])/2;
    }
    cin >> t;
    while(t--){
        cin >> n;
        int ans=1e9;
        for(int i=0;i<n;i++){
            cin >> a;
            if(res[a]/2<ans/2)ans=res[a];
        }
        cout << "Farmer " << ((ans&1)?"John":"Nhoj") << '\n';
    }
}