#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a,b;
int m,c;
string s,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    if(s.size()!=t.size()){
        cout << -1;
        return 0;
    }
    int mat[26][26];
    fill(&mat[0][0],&mat[0][0]+26*26,1e9);
    for(int i=0;i<26;i++)mat[i][i]=0;
    cin >> m;
    while(m--){
        cin >> a >> b >> c;
        a-='a';
        b-='a';
        mat[a][b]=min(mat[a][b],c);
    }
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    ll suma=0;
    string res(s.size(),' ');
    for(int i=0,n=s.size();i<n;i++){
        int mini=1e9,ind=0;
        for(int j=0;j<26;j++){
            if(mat[s[i]-'a'][j]+mat[t[i]-'a'][j]<mini){
                mini=mat[s[i]-'a'][j]+mat[t[i]-'a'][j];
                ind=j;
            }
        }
        suma+=mini;
        res[i]=ind+'a';
    }
    if(suma>=1e9)cout << -1;
    else cout << suma << '\n' << res;
}