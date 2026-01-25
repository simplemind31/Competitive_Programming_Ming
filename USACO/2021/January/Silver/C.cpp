#include <bits/stdc++.h>
using namespace std;
int n,sumr,sumc,a,row[1000][2],col[1000][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            row[i][j%2]+=a;
            col[j][i%2]+=a;
        }
    }
    for(int i=0;i<n;i++){
        sumr+=max(row[i][0],row[i][1]);
        sumc+=max(col[i][0],col[i][1]);
    }
    cout << max(sumr,sumc);
}