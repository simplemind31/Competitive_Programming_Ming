#include <bits/stdc++.h>
using namespace std;
int exis[300];
int n,dif,con,mini=1e9,l;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> st;
    dif=set(st.begin(),st.end()).size();
    for(int i=0;i<n;i++){
        con+=((++exis[st[i]-'A'])==1);
        while(con==dif){
            mini=min(mini,i-l+1);
            con-=((--exis[st[l++]-'A'])==0);
        }
    }
    cout << mini;
}