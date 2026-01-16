#include <bits/stdc++.h>
using namespace std;
int n,m,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    cin >> n >> m;
    string S[n],P[n];
    for(int i=0;i<n;i++)cin >> S[i];
    for(int j=0;j<n;j++)cin >> P[j];
    for(int i=0;i<m;i++){
        int A[4]={0,0,0,0},B[4]={0,0,0,0};
        for(int j=0;j<n;j++){
            if(S[j][i]=='A')A[0]++;
            else if(S[j][i]=='C')A[1]++;
            else if(S[j][i]=='T')A[2]++;
            else A[3]++;
            if(P[j][i]=='A')B[0]++;
            else if(P[j][i]=='C')B[1]++;
            else if(P[j][i]=='T')B[2]++;
            else B[3]++;
        }
        bool xd=true;
        for(int j=0;j<4 && xd;j++)if(A[j] && B[j])xd=false;
        if(xd)con++;
    }
    cout << con;
}