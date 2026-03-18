#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
int t,c,d,x;
vector<pair<int,int>> cla;
void euclid(int a,int b){
    if(b==0){
        return;
    }
    int q=a/b,r=a%b;
    // a=b*q1+r1
    // b=c*q2+r2
    // r=a-b*q;
    cla.push_back(cla[cla.size()-2]);
    //cla[r]=cla[a];
    cla.back().first-=cla[cla.size()-2].first*q;
    cla.back().second-=cla[cla.size()-2].second*q;
    euclid(b,a%b);
}
int main(){
    cin >> t;
    while(t--){
        cla.clear();
        cin >> c >> d >> x;
        int mcd=gcd(c,d);
        if(x%mcd){
            cout << 0 << '\n';
            continue;
        }
        c/=mcd;
        d/=mcd;
        x/=mcd;
        cla.push_back({1,0});
        cla.push_back({0,1});
        // cm+dn=1;
        euclid(c,d);
        cla.pop_back();
        cout << cla.back().first << ' ' << cla.back().second << '\n';
    }
}