#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int,int> res1,res2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int mat[n][n];
    ll di1[2*n-1],di2[2*n-1];
    memset(di1,0,sizeof(di1));
    memset(di2,0,sizeof(di2));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
            di1[i+j]+=mat[i][j];
            di2[i-j+n-1]+=mat[i][j];
        }
    }
    res1={0,0};
    res2={1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2){
                if(di1[res2.first+res2.second]+di2[res2.first-res2.second+n-1]-mat[res2.first][res2.second]<di1[i+j]+di2[i-j+n-1]-mat[i][j]){
                    res2={i,j};
                }
            }else{
                if(di1[res1.first+res1.second]+di2[res1.first-res1.second+n-1]-mat[res1.first][res1.second]<di1[i+j]+di2[i-j+n-1]-mat[i][j]){
                    res1={i,j};
                }
            }
        }
    }
    cout << di1[res2.first+res2.second]+di2[res2.first-res2.second+n-1]-mat[res2.first][res2.second]+di1[res1.first+res1.second]+di2[res1.first-res1.second+n-1]-mat[res1.first][res1.second] << '\n';
    cout << res1.first+1 << ' ' << res1.second+1 << ' ' << res2.first+1 << ' ' << res2.second+1;
}