#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int mat[n][n];
    memset(mat,0,sizeof(mat));
    vector<pair<int,int>> pos(n*n);
    mat[0][n/2]=1;
    pos[0]={0,(n)/2};
    for(int i=0;i<n*n-1;i++){
        if(pos[i].first==0 && pos[i].second!=n-1){
            pos[i+1]={n-1,pos[i].second+1};
        }else if(pos[i].second==n-1 && pos[i].first!=0){
            pos[i+1]={pos[i].first-1,0};
        }else if(pos[i].first==0){
            pos[i+1]={pos[i].first+1,pos[i].second};
        }else{
            if(pos[i].first-1>=0 && pos[i].second+1<n && mat[pos[i].first-1][pos[i].second+1]==0)pos[i+1]={pos[i].first-1,pos[i].second+1};
            else pos[i+1]={pos[i].first+1,pos[i].second};
        }
        mat[pos[i+1].first][pos[i+1].second]=i+2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j] << " \n"[j==n-1];
        }
    }
}