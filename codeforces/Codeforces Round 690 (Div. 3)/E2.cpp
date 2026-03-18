#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int MAXN=200000;
int n,t,m,k,combi[MAXN+1][101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=0;i<=MAXN;i++){
        combi[i][0]=1;
        if(i<=100)combi[i][i]=1;
        for(int j=1;j<min(i,101);j++){
            combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])%MOD;
        }
    }
    /*for(int i=0;i<=10;i++){
        for(int j=0;j<=i;j++){
            cout << combi[i][j] << ' ';
        }
        cout << endl;
    }*/
    while(t--){
        cin >> n >> m >> k;
        int nums[n],psum[n+1],res=0;
        for(int i=0;i<n;i++)cin >> nums[i];
        if(m==1){
            cout << n << '\n';
            continue;
        }
        psum[0]=combi[0][m-2];
        for(int i=1;i<=n;i++){
            psum[i]=(psum[i-1]+combi[i][m-2])%MOD;
        }
        //for(int i=0;i<=n;i++)cout << psum[i] << ' ';
        //cout << endl;
        sort(nums,nums+n);
        for(int i=0;i<n;i++){
            int pos=upper_bound(nums,nums+n,nums[i]+k)-nums-1;
            //cout << pos-i+1 << ' ';
            // del i+m-1 al pos
            // tamaño de m al pos-i+1;
            // elegir de m-2 en m-2, pos-i+1-2 en m-2;
            if(pos-i+1<m)continue;
            res=((res+((pos-i+1-2<0)?0:psum[pos-i+1-2])-((m-3<0)?0:psum[m-3]))%MOD+MOD)%MOD;
            //cout << res << '\n';
        }
        cout << res << '\n';
    }
}