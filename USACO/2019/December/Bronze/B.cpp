#include <bits/stdc++.h>
using namespace std;
int n;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
    cin >> n >> st;
    unordered_map<string,int> con[n];
    for(int i=0;i<n;i++){
        string now="";
        for(int j=i;j<n;j++){
            now.push_back(st[j]);
            con[j-i][now]++;
        }
    }
    for(int i=0;i<n;i++){
        bool xd=true;
        for(auto u:con[i]){
            if(u.second>1){
                xd=false;
                break;
            }
        }
        if(xd){
            cout << i+1;
            return 0;
        }
    }
}