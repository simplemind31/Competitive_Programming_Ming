#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MAXN=1000001;
int n,a;
bitset<MAXN> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        con[a]=true;
    }
    a=0;
    for(int i=MAXN-1;i>=1;i--){
        if(con[i])continue;
        int mcd=0;
        for(int j=i+i;j<MAXN && mcd!=1;j+=i){
            if(con[j])mcd=gcd(mcd,j/i);
        }
        if(mcd==1){
            a++;
            con[i]=1;
        }
    }
    cout << a;
}