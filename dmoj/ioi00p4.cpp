#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n,l,member[30],a;
vector<int> region[200],town[250];
int muro[250][250],;
bool edge[200][200];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n >> l;
    memset(muro,-1,sizeof(muro));
    for(int i=0;i<l;i++)cin >> member[i];
    for(int i=0;i<m;i++){
        cin >> a;
        region[i].resize(a);
        for(int j=0;j<a;j++){
            cin >> region[i][j];
            town[--region[i][j]].push_back(i);
            if(j)muro[region[i][j-1]][region[i][j]]=i;
        }
        muro[region[i][a-1]][region[i][0]]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(muro[i][j]==-1 || muro[j][i]==-1)continue;
            edge[muro[i][j]][muro[j][i]]=edge[muro[j][i]][muro[i][j]]=1;
        }
    }
}