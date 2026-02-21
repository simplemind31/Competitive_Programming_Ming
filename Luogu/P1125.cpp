#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int con[26],maxi,mini=1e9;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(auto u:st)con[u-'a']++;
    for(int i=0;i<26;i++){
        if(con[i]==0)continue;
        maxi=max(maxi,con[i]);
        mini=min(mini,con[i]);
    }
    if(maxi-mini<=1){
        cout << "No Answer\n0";
        return 0;
    }
    for(int i=2;i*i<=maxi-mini;i++){
        if((maxi-mini)%i==0){
            cout << "No Answer\n0";
            return 0;
        }
    }
    cout << "Lucky Word\n" << maxi-mini;
}