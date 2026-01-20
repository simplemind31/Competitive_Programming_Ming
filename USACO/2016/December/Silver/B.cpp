#include <bits/stdc++.h>
using namespace std;
int n,tot;
string a,b;
map<string,int> con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    cin >> n;
    while(n--){
        cin >> a >> b;
        string fi="",sec="";
        fi.push_back(a[0]);
        fi.push_back(a[1]);
        sec.push_back(b[0]);
        sec.push_back(b[1]);
        if(fi!=sec)tot+=con[sec+fi];
        con[fi+sec]++;
    }
    cout << tot;
}