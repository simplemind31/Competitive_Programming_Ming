#include <bits/stdc++.h>
using namespace std;
char c;
int n,m,con0;
pair<int,int> fir0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bcs.in","r",stdin);
    freopen("bcs.out","w",stdout);
    cin >> n >> m;
    int con[m];
    pair<int,int> fir[m];
    vector<vector<bool>> fig(n,vector<bool>(n)),cop,broken[m];
    for(int i=0;i<m;i++){
        fir[i]={-1,-1};
        con[i]=0;
        broken[i]=fig;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c=='#'){
                fig[i][j]=1;
                con0++;
                if(fir0.first==-1)fir0={i,j};
            }
        }
    }
    for(int k=0;k<m;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> c;
                if(c=='#'){
                    broken[k][i][j]=1;
                    con[k]++;
                    if(fir[k].first==-1)fir[k]={i,j};
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(con[i]+con[j]!=con0)continue;
            int a=i,b=j;
            //fir[a]=fir0
            cop=fig;
            bool xd=true;
            for(int k)
        }
    }
}