#include <bits/stdc++.h>
using namespace std;
bool xd;
int q,a,b,con,n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    n=st.size();
    vector<vector<int>> psum(n+1,vector<int>(26));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++)psum[i+1][j]=psum[i][j];
        psum[i+1][st[i]-'a']++;
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        for(int i=con=0;i<26 && !xd && con<3;i++)if(psum[b][i]-psum[a-1][i])con++;
        if((st[a-1]!=st[b-1])||(a==b)||(con>2)) cout << "Yes\n";
        else cout << "No\n";
    }
}
