#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,m,mat[1003][1003];
bool expandido[1003][1003];
vector<pair<pair<int,int>,int>> res;
void check(int x,int y);
void expandir(int x,int y){
    if(expandido[x][y])return;
    expandido[x][y]=true;
    check(x-1,y-1);
    check(x-1,y);
    check(x,y-1);
    check(x,y);
}
void check(int x,int y){
    int color=0;
    if(mat[x][y]==-1 || mat[x+1][y]==-1 || mat[x][y+1]==-1 || mat[x+1][y+1]==-1)return;
    if(mat[x][y]!=0)color=mat[x][y];
    if(mat[x+1][y]!=0)color=mat[x+1][y];
    if(mat[x][y+1]!=0)color=mat[x][y+1];
    if(mat[x+1][y+1]!=0)color=mat[x+1][y+1];
    if(color==0)return;
    int con0=(mat[x][y]==0)+(mat[x+1][y]==0)+(mat[x][y+1]==0)+(mat[x+1][y+1]==0);
    int con1=(mat[x][y]==color)+(mat[x+1][y]==color)+(mat[x][y+1]==color)+(mat[x+1][y+1]==color);
    if(con0+con1==4){
        res.push_back({{x,y},color});
        mat[x][y]=mat[x+1][y]=mat[x][y+1]=mat[x+1][y+1]=0;
        expandir(x,y);
        expandir(x+1,y);
        expandir(x,y+1);
        expandir(x+1,y+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    memset(mat,-1,sizeof(mat));
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            check(i,j);
        }
    }
    bool xd=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]!=0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << res.size() << '\n';
    reverse(ALL(res));
    for(auto u:res){
        cout << u.first.first << ' ' << u.first.second << ' ' << u.second << '\n';
    }
}