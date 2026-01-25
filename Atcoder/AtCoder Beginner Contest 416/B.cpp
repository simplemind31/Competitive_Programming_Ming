#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
bool xd,lol;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    t=s;
    for(int i=0,n=s.size();i<n;i++){
        if(!xd && t[i]=='.'){
            xd=true;
            lol=false;
            t[i]='o';
        }else if(t[i]=='#'){
            lol=true;
        }else if(lol){
            lol=false;
            t[i]='o';
        }
    }
    cout << t;
}