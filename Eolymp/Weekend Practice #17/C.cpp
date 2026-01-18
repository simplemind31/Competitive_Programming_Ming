#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
int n,m,con1,con2,mini=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    bool mat[n][m],verd[n][m],copverd[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            copverd[i][j]=verd[i][j]=(mat[i][j]==mat[n-i-1][m-j-1]);
        }
    }
    //row0=1
    for(int j=0;j<m;j++){
        if(verd[0][j])continue;
        if((m&1) && (j==m/2))continue;
        con1++;
        for(int i=0;i<n;i++){
            verd[i][j]=verd[n-i-1][m-j-1]=!verd[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(verd[i][0])continue;
        if((n&1) && (i==n/2))continue;
        con1++;
        for(int j=0;j<m;j++){
            verd[i][j]=verd[n-i-1][m-j-1]=!verd[i][j];
        }
    }
    bool xd=true;
    for(int i=0;i<n && xd;i++){
        for(int j=0;j<m && xd;j++){
            xd=verd[i][j];
        }
    }
    if(xd){
        mini=min(mini,con1);
    }
    con1=0;
    //row0=0
    for(int j=0;j<m;j++){
        if(copverd[0][j]==0)continue;
        if((m&1) && (j==m/2))continue;
        con1++;
        for(int i=0;i<n;i++){
            copverd[i][j]=copverd[n-i-1][m-j-1]=!copverd[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(copverd[i][0])continue;
        if((n&1) && (i==n/2))continue;
        con1++;
        for(int j=0;j<m;j++){
            copverd[i][j]=copverd[n-i-1][m-j-1]=!copverd[i][j];
        }
    }
    xd=true;
    for(int i=0;i<n && xd;i++){
        for(int j=0;j<m && xd;j++){
            xd=copverd[i][j];
        }
    }
    if(xd){
        mini=min(mini,con1);
    }
    if(mini==1e9)cout << -1;
    else cout <<mini;
}