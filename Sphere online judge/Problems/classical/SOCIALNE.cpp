#include <bits/stdc++.h>
using namespace std;
int t,n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> st;
        n=st.size();
        int mat[n][n];
        for(int j=0;j<n;j++)mat[0][j]=st[j]=='Y'?1:1e9;
        for(int i=1;i<n;i++){
            cin >> st;
            for(int j=0;j<n;j++)mat[i][j]=st[j]=='Y'?1:1e9;
        }
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
        int maxi=0,ind=0;
        for(int i=0;i<n;i++){
            int con=0;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(mat[i][j]==2)con++;
            }
            if(con>maxi){
                maxi=con;
                ind=i;
            }
        }
        cout << ind << ' ' << maxi << '\n';
    }
}