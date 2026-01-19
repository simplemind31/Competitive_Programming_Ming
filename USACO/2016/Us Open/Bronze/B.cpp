#include <bits/stdc++.h>
using namespace std;
char c;
int n,m,con0;
pair<int,int> fir0={-1,-1};
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
        for(int j=0;j<m;j++){
            if(i==j)continue;
            if(con[i]+con[j]!=con0)continue;
            //if(i==0 && j==2)continue;
            cop=fig;
            pair<int,int> copfir0=fir0;
            //cout << fir[i].first << ' ' << fir[i].second << '\n';
            bool xd=true;
            for(int k=0;k<n && xd;k++){
                for(int l=0;l<n && xd;l++){
                    //cout << k << ' ' << l << ' ' << k+fir[i].first-copfir0.first << ' ' << l+fir[i].second-copfir0.second << '\n';
                    //fir0.first,fir0.second->fir[i].first,fir[i].second
                    // cop[0][0]->broken[fir[i].first-fir0.frist][fir[i].second-fir0.second];
                    if(k+fir[i].first-copfir0.first<0 || k+fir[i].first-copfir0.first>=n || l+fir[i].second-copfir0.second<0 || l+fir[i].second-copfir0.second>=n)continue;
                    if(broken[i][k+fir[i].first-copfir0.first][l+fir[i].second-copfir0.second]){
                        xd=cop[k][l];
                        cop[k][l]=0;
                    }
                }
            }
            if(xd){
                copfir0.first=-1;
                for(int k=0;k<n && copfir0.first==-1;k++){
                    for(int l=0;l<n && copfir0.first==-1;l++){
                        if(cop[k][l])copfir0={k,l};
                    }
                }
                for(int k=0;k<n && xd;k++){
                    for(int l=0;l<n && xd;l++){
                        if(k+fir[j].first-copfir0.first<0 || k+fir[j].first-copfir0.first>=n || l+fir[j].second-copfir0.second<0 || l+fir[j].second-copfir0.second>=n)continue;
                        if(cop[k][l]!=broken[j][k+fir[j].first-copfir0.first][l+fir[j].second-copfir0.second])xd=false;
                        cop[k][l]=0;
                    }
                }
                for(int k=0;k<n && xd;k++){
                    for(int l=0;l<n && xd;l++){
                        xd=!cop[k][l];
                    }
                }
            }
            if(xd){
                cout << min(i,j)+1 << ' ' << max(i,j)+1;
                return 0;
            }
        }
    }
}