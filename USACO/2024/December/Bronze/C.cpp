#include <bits/stdc++.h>
using namespace std;
bool posi[26*26];
int n,f,con[26*26];
string st;
bool moo(int pos){return (st[pos]!=st[pos+1]&&st[pos+1]==st[pos+2]);}
int ha(int pos){return 26*(st[pos]-'a')+(st[pos+1]-'a');}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> f >> st;
    for(int i=0;i<n-2;i++){
        if(moo(i)){
            if(++con[ha(i)]>=f)posi[ha(i)]=true;
        }
    }
    for(int i=0;i<n;i++){
        //cambiar st[i]
        if(i-2>=0 && moo(i-2))con[ha(i-2)]--;
        if(i-1>=0 && i+1<n && moo(i-1))con[ha(i-1)]--;
        if(i+2<n && moo(i))con[ha(i)]--;
        char ori=st[i];
        for(int j=0;j<26;j++){
            char nue=j+'a';
            st[i]=nue;
            if(i-2>=0 && moo(i-2))if(++con[ha(i-2)]>=f)posi[ha(i-2)]=true;
            if(i-1>=0 && i+1<n && moo(i-1))if(++con[ha(i-1)]>=f)posi[ha(i-1)]=true;
            if(i+2<n && moo(i))if(++con[ha(i)]>=f)posi[ha(i)]=true;
            if(i-2>=0 && moo(i-2))con[ha(i-2)]--;
            if(i-1>=0 && i+1<n && moo(i-1))con[ha(i-1)]--;
            if(i+2<n && moo(i))con[ha(i)]--;
        }
        st[i]=ori;
        if(i-2>=0 && moo(i-2))con[ha(i-2)]++;
        if(i-1>=0 && i+1<n && moo(i-1))con[ha(i-1)]++;
        if(i+2<n && moo(i))con[ha(i)]++;
    }
    vector<pair<int,int>> res;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(posi[i*26+j])res.push_back({i,j});
        }
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << char(u.first+'a') << char(u.second+'a') << char(u.second+'a') << '\n';
    }
}