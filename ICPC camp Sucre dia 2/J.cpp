#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string dep[]={"ch","lp","cbba","or","pt","tja","scz","be","pd"};
int n,res;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    res=n;
    while(n--){
        cin >> st;
        bool xd=false;
        for(int i=0;i<9 && !xd;i++)xd=st==dep[i];
        res-=xd;
    }
    cout << res;
}