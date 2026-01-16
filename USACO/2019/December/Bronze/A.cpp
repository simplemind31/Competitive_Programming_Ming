#include <bits/stdc++.h>
using namespace std;
int k,n,a,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    cin >> k >> n;
    int ord[k][n];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            ord[i][a-1]=j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            bool xd=true;
            for(int l=1;l<k && xd;l++){
                if((ord[l][i]>ord[l][j])!=(ord[0][i]>ord[0][j]))xd=false;
            }
            if(xd)con++;
        }
    }
    cout << con;
}