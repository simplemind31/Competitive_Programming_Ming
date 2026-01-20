#include <bits/stdc++.h>
using namespace std;
int n,a;
string anim;
unordered_map<string,int> cows;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    cin >> n;
    cows["Bessie"]=cows["Maggie"]=cows["Elsie"]=cows["Henrietta"]=cows["Annabelle"]=cows["Daisy"]=cows["Gertie"]=0;
    while(n--){
        cin >> anim >> a;
        cows[anim]+=a;
    }
    vector<pair<int,string>> ord;
    for(auto u:cows)ord.push_back({u.second,u.first});
    sort(ord.begin(),ord.end());
    bool xd=false;
    for(int i=1;i<7;i++){
        if(xd){
            if(ord[i].first!=ord[i-1].first){
                cout << ord[i-1].second <<'\n';
                return 0;
            }else{
                cout << "Tie\n";
                return 0;
            }
        }else if(ord[i].first!=ord[i-1].first){
            xd=true;
        }
    }
    if(xd)cout << ord[6].second << '\n';
    else cout << "Tie\n";
}