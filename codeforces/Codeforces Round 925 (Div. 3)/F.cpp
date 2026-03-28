#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<vector<int>> mat(k,vector<int>(n));
        vector<int> punt(k,1);
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
                mat[i][j]--;
            }
        }
        if(k==1){
            cout << "YES\n";
            continue;
        }
        if(k==2){
            int i=0,j=0;
            bool xd=true;
            while(i<n || j<n){
                while(i<n && (mat[0][i]==mat[0][0] || mat[0][i]==mat[1][0]))i++;
                while(j<n && (mat[1][j]==mat[0][0] || mat[1][j]==mat[1][0]))j++;
                if(i==n && j==n)break;
                if(i==n || j==n)xd=false;
                else if(mat[0][i]!=mat[1][j])xd=false;
                i++;
                j++;
            }
            if(xd)cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        vector<int> con(n);
        bool xd=true;
        int mini=1;
        for(int i=1;mini<n && xd;i++){
            int may=-1,conmay=0;
            for(int j=0;j<k && xd && conmay<2;j++){
                if(punt[j]==n){
                    conmay++;
                    continue;
                }
                if(++con[mat[j][punt[j]]]==2 && may==-1)may=mat[j][punt[j]];
                else if(con[mat[j][punt[j]]]==2)xd=false;
            }
            if(conmay>=2)xd=false;
            mini=1e9;
            if(may==-1)xd=false;
            for(int j=0;j<k && xd;j++){
                if(punt[j]==n)continue;
                con[mat[j][punt[j]]]--;
                if(mat[j][punt[j]]==may)punt[j]++;
                mini=min(mini,punt[j]);
            }
        }
        if(xd)cout << "YES\n";
        else cout << "NO\n";
    }
}