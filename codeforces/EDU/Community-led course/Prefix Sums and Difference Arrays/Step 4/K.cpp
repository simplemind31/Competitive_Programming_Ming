#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,q,l,r;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    // 448
    while(t--){
        cin >> n >> m;
        int psum[n+1][m],nums[n+1][m];
        for(int j=0;j<m;j++)nums[0][j]=psum[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                cin >> nums[i][j];
                nums[i][j]--;
            }
            for(int j=0;j<m;j++){
                psum[i][j]=nums[i][psum[i-1][j]];
                //cout << psum[i][j]+1 << ' ';
            }
            //cout << '\n';
        }
        // todo bien hasta ahora
        cin >> q;
        if(n<=448){
            ll res[n+1][n+1];
            memset(res,0,sizeof(res));
            while(q--){
                cin >> l >> r;
                if(res[l][r]==0){
                    for(int j=0;j<m;j++){
                        res[l][r]+=1ll*(psum[l-1][j]+1)*(psum[r][j]+1);
                    }
                }
                cout << res[l][r] << '\n';
            }
        }else{
            while(q--){
                cin >> l >> r;
                ll sum=0;
                for(int j=0;j<m;j++){
                    sum+=1ll*(psum[l-1][j]+1)*(psum[r][j]+1);
                }
                cout << sum << '\n';
            }
        }
    }
}