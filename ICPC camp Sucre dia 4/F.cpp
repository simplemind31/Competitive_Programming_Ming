#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
int t,n;
string a;
string operator-(string x,string y){
    if(y.size()<x.size()){
        reverse(ALL(y));
        y.push_back('0');
        reverse(ALL(y));
    }
    n=x.size();
    string res(n,'0');
    // 111111
    // 099999
    int sobra=0;
    for(int i=n-1;i>=0;i--){
        int di=x[i]-'0'-sobra-(y[i]-'0');
        //cout << x[i] << ' ' << y[i] << '\n';
        sobra=0;
        if(di<0){
            sobra=1;
            di+=10;
        }
        res[i]=di+'0';
    }
    //9999
    //1023
    reverse(ALL(res));
    if(res.back()=='0')res.pop_back();
    reverse(ALL(res));
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a;
        if(a[0]!='9')cout << string(n,'9')-a << '\n';
        else cout << string(n+1,'1')-a << '\n';
        // 99123
        // 99999
        //111111
    }
}
