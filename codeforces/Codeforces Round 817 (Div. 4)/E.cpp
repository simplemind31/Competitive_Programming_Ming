#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,q,t,a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<int> mat[1001];
        for(int i=0;i<=1000;i++)mat[i].push_back(0);
        vector<ll> psum[1001];
        for(int i=0;i<n;i++){
            cin >> a >> b;
            mat[a].push_back(b);
        }
        for(int i=0;i<=1000;i++){
            sort(ALL(mat[i]));
            psum[i].resize(mat[i].size());
            for(int j=1;j<mat[i].size();j++)psum[i][j]=psum[i][j-1]+mat[i][j];
        }
        while(q--){
            //cualquiera menor o igual al primer rec
            cin >> a >> b >> c >> d;
            // menor o igual a a,b
            // menor c,d - menor igual c,b -menor igual a,d+menor igual a,b
            ll sum1=0;
            for(int i=a+1;i<c;i++){
                int pos1=upper_bound(ALL(mat[i]),b)-mat[i].begin();
                int pos2=lower_bound(ALL(mat[i]),d)-mat[i].begin()-1;
                sum1+=(psum[i][pos2]-psum[i][pos1-1])*i;
            }
            cout << sum1 << '\n';
        }
    }
}