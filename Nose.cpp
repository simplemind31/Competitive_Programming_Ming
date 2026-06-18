#include <bits/stdc++.h>
using namespace std;
int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int mod=1e9+7,B=uniform_int_distribution<int>(1,mod-1)(rng);
    vector<int> valor(26);
    for(int i=0;i<26;i++)valor[i]=uniform_int_distribution<int>(2,mod-1)(rng);
    string st="absdjnas";
    int ha=0;
    for(int i=0;i<st.size();i++){
        ha=1ll*B*ha%mod;
        ha=(ha+valor[st[i]-'a'])%mod;
    }
    cout << ha;
}
