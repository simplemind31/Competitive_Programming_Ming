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
        for(int j=i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                unordered_map<int,bool> a,b;
                for(int l=0;l<n;l++){
                    a[(S[l][i]-'A')*10000+(S[l][j]-'A')*100+S[l][k]]=b[(P[l][i]-'A')*10000+(P[l][j]-'A')*100+P[l][k]]=true;
                }
                bool xd=true;
                for(auto u:a){
                    if(b[u.first]){
                        xd=false;
                        break;
                    }
                }
                if(xd)con++;
            }
        }
    }
    cout << con;
}