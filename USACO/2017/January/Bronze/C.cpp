#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int n,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    cin >> n;
    bool mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            mat[i][j]=c-'0';
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(mat[i][j]){
                con++;
                for(int k=0;k<=i;k++){
                    for(int l=0;l<=j;l++){
                        mat[k][l]=!mat[k][l];
                    }
                }
            }
        }
    }
    cout << con;
}