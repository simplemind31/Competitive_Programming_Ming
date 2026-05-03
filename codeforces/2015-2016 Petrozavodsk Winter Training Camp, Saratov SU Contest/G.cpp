#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string a,b,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    reverse(ALL(a));
    while(a.size()<b.size())a.push_back('0');
    reverse(ALL(a));
    ll ante=1,maxi=0;
    string now="";
    bool xd=false;
    bool lol=false;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i] || lol){
            // elijo b[i]-1 y el resto 9
            lol=true;
            ll val;
            if(b[i]-'0'-1==0 && !xd)val=ante*pow(9,a.size()-i-1);
            else val=ante*(b[i]-'0'-1)*pow(9,a.size()-i-1);
            //cout << val << ' ';
            if(val>=maxi){
                maxi=val;
                res=now+char(b[i]-1)+string(a.size()-i-1,'9');
            }
        }
        if(b[i]!='0')xd=true;
        now+=b[i];
        ante*=b[i]-'0';
        //cout << ante << ' ' << now << '\n';
    }
    if(ante>=maxi){
        maxi=ante;
        res=now;
    }
    reverse(ALL(res));
    while(!res.empty() && res.back()=='0')res.pop_back();
    reverse(ALL(res));
    if(res.empty())res="0";
    cout << res;
}