#include <bits/stdc++.h>
using namespace std;
int t,n,k,maxi,con;
string f,s;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=true;
        cin >> n >> k;
        cin >> f >> s;
        vector<vector<int>> last(n,vector<int>(26,-1));
        vector<int> nece(n);
        last[0][f[0]-'a']=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++)last[i][j]=last[i-1][j];
            last[i][f[i]-'a']=i;
        }
        nece[n-1]=last[n-1][s[n-1]-'a'];
        maxi=n-1-nece[n-1];
        if(nece[n-1]==-1)xd=false;
        for(int i=n-2;i>=0 && xd;i--){
            nece[i]=last[min(nece[i+1],i)][s[i]-'a'];
            maxi=max(maxi,i-nece[i]);
            if(nece[i]==-1)xd=false;
        }
        if(!xd || maxi>k){
            cout << "-1\n";
            continue;
        }
        if(maxi==0){
            cout << "0\n";
            continue;
        }
        vector<string> res(maxi,string(n,' '));
        res[maxi-1]=s;
        for(int i=n-1;i>=0;i--){
            int j=nece[i];
            int con=0;
            while(j<i)res[con++][++j]=s[i];
            while(con<maxi-1)res[con++][j]=s[i];
        }
        for(int i=0;i<n;i++)if(res[0][i]==' ')res[0][i]=f[i];
        for(int i=1;i<maxi;i++)for(int j=0;j<n;j++)if(res[i][j]==' ')res[i][j]=res[i-1][j];
        cout << maxi << '\n';
        for(int i=0;i<maxi;i++)cout << res[i] << '\n';
    }
}